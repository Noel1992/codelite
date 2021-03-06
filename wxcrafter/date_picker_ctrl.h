#ifndef DATEPICKERCTRL_H
#define DATEPICKERCTRL_H

#include "wxc_widget.h" // Base class: WrapperBase

class DatePickerCtrl : public wxcWidget
{

public:
    DatePickerCtrl();
    virtual ~DatePickerCtrl();

public:
    virtual wxcWidget* Clone() const;
    virtual wxString CppCtorCode() const;
    virtual void GetIncludeFile(wxArrayString& headers) const;
    virtual wxString GetWxClassName() const;
    virtual void ToXRC(wxString& text, XRC_TYPE type) const;
};

#endif // DATEPICKERCTRL_H
