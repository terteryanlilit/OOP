#include "commandPane.h"

namespace GUI
{
	
CommandPane::CommandPane(QWidget* pParent)
	: QDockWidget(pParent)
{
	ui.setupUi(this);

	ui.textEdit->setReadOnly(true);
	ui.textEdit->setAcceptRichText(true);
	ui.textEdit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
}


void CommandPane::scrollTextEdit(QTextCursor::MoveOperation op) const
{
	QTextCursor c = ui.textEdit->textCursor();
	c.movePosition(op);
	ui.textEdit->setTextCursor(c);
}
	
}
