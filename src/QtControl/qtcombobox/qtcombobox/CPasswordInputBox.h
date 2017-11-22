#ifndef CPASSWORDINPUTBOX_H
#define CPASSWORDINPUTBOX_H

#include <QLineEdit>
#include <COriginalButton.h>

class CPasswordInputBox : public QLineEdit
{
    Q_OBJECT
public:
    CPasswordInputBox(QWidget* parent = NULL);
    ~CPasswordInputBox();

private:
    COriginalButton* mMaskButton;

    void layoutControl();
    void resizeEvent(QResizeEvent *e);

private slots:
    void onMaskButtonClicked();

};

#endif // CPASSWORDINPUTBOX_H
