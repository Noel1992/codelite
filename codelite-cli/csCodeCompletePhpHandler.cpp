#include "PHPExpression.h"
#include "PHPLookupTable.h"
#include "PHPSourceFile.h"
#include "csCodeCompletePhpHandler.h"

csCodeCompletePhpHandler::csCodeCompletePhpHandler(wxEvtHandler* sink)
    : csCommandHandlerBase(sink)
{
}

csCodeCompletePhpHandler::~csCodeCompletePhpHandler() {}

void csCodeCompletePhpHandler::DoProcessCommand(const JSONElement& options)
{
    CHECK_STR_PARAM("path", m_path);
    CHECK_INT_PARAM("position", m_position);
    CHECK_STR_PARAM("symbols-path", m_symbolsPath);

    // Guess the symbols db path
    PHPLookupTable lookup;
    if(wxFileName::DirExists(m_symbolsPath)) {
        // the provided path is the folder, build the symbols path
        m_symbolsPath << wxFileName::GetPathSeparator() << ".codelite" << wxFileName::GetPathSeparator()
                      << "phpsymbols.db";
    }
    clDEBUG() << "Using symbols db:" << m_symbolsPath;
    lookup.Open(wxFileName(m_symbolsPath));
    if(!lookup.IsOpened()) {
        return;
    }

    PHPSourceFile sourceFile(wxFileName(m_path), &lookup);
    sourceFile.SetParseFunctionBody(true);
    sourceFile.Parse();
    lookup.UpdateSourceFile(sourceFile);
    PHPExpression::Ptr_t expr(new PHPExpression(sourceFile.GetText().Mid(0, m_position)));
    PHPEntityBase::Ptr_t resolved = expr->Resolve(lookup, m_path);
    if(resolved) {
        PHPEntityBase::List_t matches = lookup.FindChildren(
            resolved->GetDbId(), PHPLookupTable::kLookupFlags_StartsWith | expr->GetLookupFlags(), expr->GetFilter());
        JSONRoot root(cJSON_Array);
        JSONElement arr = root.toElement();
        std::for_each(matches.begin(), matches.end(), [&](PHPEntityBase::Ptr_t e) { arr.arrayAppend(e->ToJSON()); });
        char* result = arr.FormatRawString(true);
        std::cout << result << std::endl;
        free(result);

    } else {
        std::cout << "[]" << std::endl;
    }
}
