#include "CMS.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CMS w;
	w.show();
	return a.exec();
}
