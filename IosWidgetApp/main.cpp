#include <QtGui>
#if QT_VERSION >= 0x050000
#include <QtWidgets>
#endif

#define SUPERCLASS QWidget

class TestWidget : public SUPERCLASS
{
    Q_OBJECT

public:
    TestWidget(QWidget *parent = 0, QString name = "") : SUPERCLASS(parent)
    {
        setObjectName(name);
        QVBoxLayout *l = new QVBoxLayout();
        this->setLayout(l);

        QLabel *label = new QLabel(name);
        QPushButton *pbutton = new QPushButton("Kaboom!");
        QPushButton *cbutton = new QPushButton("Close");

        connect(pbutton, SIGNAL(clicked()), this, SLOT(kaboom()));
        connect(cbutton, SIGNAL(clicked()), this, SLOT(close()));

        l->addWidget(label);
        l->addWidget(pbutton);
        l->addWidget(cbutton);
    }

public slots:
    void kaboom()
    {
        QMessageBox::information(this, "Hi", "KABOOM!");
    }
};

#include "main.moc"

int main(int argc, char **argv){
    QApplication app(argc, argv);
    TestWidget wid1(0, "TestWidget1");
    wid1.show();
    return app.exec();
}

