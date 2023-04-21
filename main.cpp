#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class FontSizeChanger : public QWidget {
public:
    FontSizeChanger(QWidget *parent = nullptr) : QWidget(parent) {
        // Создаем компоненты интерфейса
        QLabel *label = new QLabel("Hello, World!", this);
        QPushButton *plusButton = new QPushButton("+", this);
        QPushButton *minusButton = new QPushButton("-", this);
        QLabel *sizeLabel = new QLabel(QString::number(label->font().pointSize()), this);

        // Создаем менеджер компоновки и добавляем в него компоненты интерфейса
        QHBoxLayout *layout = new QHBoxLayout(this);
        layout->addWidget(label);
        layout->addWidget(plusButton);
        layout->addWidget(minusButton);
        layout->addWidget(sizeLabel);

        // Подключаем обработчики событий
        connect(plusButton, &QPushButton::clicked, this, &FontSizeChanger::increaseFontSize);
        connect(minusButton, &QPushButton::clicked, this, &FontSizeChanger::decreaseFontSize);

        // Устанавливаем размер компонента
        setFixedSize(400, 200);
    }

private slots:
    void increaseFontSize() {
        QLabel *label = findChild<QLabel *>();
        QFont font = label->font();
        font.setPointSize(font.pointSize() + 1);
        label->setFont(font);

        QLabel *sizeLabel = findChild<QLabel *>(QString(), Qt::FindDirectChildrenOnly);
        sizeLabel->setText(QString::number(font.pointSize()));
    }

    void decreaseFontSize() {
        QLabel *label = findChild<QLabel *>();
        QFont font = label->font();
        font.setPointSize(font.pointSize() - 1);
        label->setFont(font);

        QLabel *sizeLabel = findChild<QLabel *>(QString(), Qt::FindDirectChildrenOnly);
        sizeLabel->setText(QString::number(font.pointSize()));
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FontSizeChanger widget;
    widget.show();

    return app.exec();
}
