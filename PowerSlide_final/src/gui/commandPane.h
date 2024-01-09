#ifndef GUI_COMMANDPANE_H
#define GUI_COMMANDPANE_H

#include "ui_CommandPane.h"


namespace GUI
{

class CommandPane : public QDockWidget
{
	Q_OBJECT
public:
	CommandPane(QWidget* pParent = nullptr);

private:
	void scrollTextEdit(QTextCursor::MoveOperation op) const;

private:
	Ui::CommandDockWidget ui;
};

}

#endif