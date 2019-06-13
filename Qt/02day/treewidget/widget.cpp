#include "widget.h"
#include "ui_widget.h"
#include <QStringList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList lists;
    lists<<"名称"<<"描述";
    ui->treeWidget->setHeaderLabels(lists);


    QTreeWidgetItem *lItem = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *mItem = new QTreeWidgetItem(QStringList()<<"智慧");
    QTreeWidgetItem *zItem = new QTreeWidgetItem(QStringList()<<"敏捷");

    ui->treeWidget->addTopLevelItem(lItem);
    ui->treeWidget->addTopLevelItem(mItem);
    ui->treeWidget->addTopLevelItem(zItem);

    QStringList heroL1;
    QStringList heroL2;
    heroL1 << "刚被猪" << "前排坦克，能在吸收伤害的同时造成可观的范围输出";
    heroL2 << "船长" << "前排坦克，能肉能输出能控场的全能英雄";
    QTreeWidgetItem *L1 = new QTreeWidgetItem(heroL1);
    QTreeWidgetItem *L2 = new QTreeWidgetItem(heroL2);
    lItem->addChild(L1);
    lItem->addChild(L2);


    QStringList heroM1;
    QStringList heroM2;
    heroM1 << "月骑" << "中排物理输出，可以使用分裂利刃攻击多个目标";
    heroM2 << "小鱼人" << "前排战士，擅长偷取敌人的属性来增强自身战力";
    QTreeWidgetItem *M1 = new QTreeWidgetItem(heroM1);
    QTreeWidgetItem *M2 = new QTreeWidgetItem(heroM2);
    mItem->addChild(M1);
    mItem->addChild(M2);

    QStringList heroZ1;
    QStringList heroZ2;
    heroZ1 << "死灵法师" << "前排法师坦克，魔法抗性较高，拥有治疗技能";
    heroZ2 << "巫医" << "后排辅助法师，可以使用奇特的巫术诅咒敌人与治疗队友";
    QTreeWidgetItem *Z1 = new QTreeWidgetItem(heroZ1);
    QTreeWidgetItem *Z2 = new QTreeWidgetItem(heroZ2);
    zItem->addChild(Z1);
    zItem->addChild(Z2);
}

Widget::~Widget()
{
    delete ui;
}
