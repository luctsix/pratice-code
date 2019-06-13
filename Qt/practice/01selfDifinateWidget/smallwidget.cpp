#include "smallwidget.h"

#include <QHBoxLayout>

SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{
    resize(400, 100);

    spin   = new QSpinBox(this);
    //spin->setMaximum(100);
    slider = new QSlider(Qt::Horizontal,this);

    //创建布局对象
    QHBoxLayout *layout = new QHBoxLayout(this);
    //将控件添加到布局
    layout->addWidget(spin);
    layout->addWidget(slider);
    //将布局设置到窗口
    setLayout(layout);

    //添加消息响应
    connect(spin, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider, &QSlider::setValue);
    connect(slider, &QSlider::valueChanged,
            spin,   &QSpinBox::setValue);


}
