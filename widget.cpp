#include "widget.h"
#include <QtWidgets>
#include <QLayout>
#include <QMessageBox>
#include <QDebug>
#include <QStyle>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    text=new QTextEdit(this);
    calbt=new QPushButton(tr("计算"));
    quitbt=new QPushButton(tr("退出"));

    connect(calbt,SIGNAL(clicked()),this,SLOT(calu()));
    connect(quitbt,SIGNAL(clicked()),qApp,SLOT(quit()));

    QHBoxLayout *btlayout=new QHBoxLayout;
    QVBoxLayout *mainlayout=new QVBoxLayout;
    btlayout->addWidget(calbt);
    btlayout->addWidget(quitbt);
    mainlayout->addWidget(text);
    mainlayout->addLayout(btlayout);
    setLayout(mainlayout);
}
QString Widget::Tf(QString name,int x)
{
    QStringList tfm;
    tfm<<"0"<<"1"<<"血迪凯"<<"冰迪凯"<<"邪迪凯"<<"5"
      <<"鸟德"<<"猫德"<<"熊德"<<"奶德"
       <<"兽王猎"<<"生存猎"<<"射击猎"<<"13"
      <<"奥法"<<"火法"<<"冰法"
     <<"酒仙"<<"奶僧"<<"风僧"
    <<"奶骑"<<"防骑"<<"惩戒骑"
     <<"戒律牧"<<"神牧"<<"暗牧"
       <<"刺杀贼"<<"战斗贼"<<"敏锐贼"
       <<"元素萨"<<"增强萨"<<"奶萨"
       <<"痛苦术"<<"恶魔术"<<"毁灭术"
      <<"武器战"<<"36"<<"狂暴战"<<"防战";
    QStringList zycol;
    zycol<<"<font color=darkred>"<<"<font color=orange>"<<"<font color=darkgreen>"
        <<"<font color=lightblue>"<<"<font color=lightgreen>"<<"<font color=pink>"
       <<"<font color=white>"<<"<font color=yellow>"<<"<font color=darkblue>"
      <<"<font color=purple>"<<"<font color=brown>";
     QString tmp=name+"("+tfm[x]+")";
     switch(x)
     {
        case 2:case 3:case 4:tmp=zycol[0]+tmp+"</font>";break;
        case 6:case 7:case 8:case 9:tmp=zycol[1]+tmp+"</font>";break;
        case 10:case 11:case 12:tmp=zycol[2]+tmp+"</font>";break;
         case 14:case 15:case 16:tmp=zycol[3]+tmp+"</font>";break;
         case 17:case 18:case 19:tmp=zycol[4]+tmp+"</font>";break;
         case 20:case 21:case 22:tmp=zycol[5]+tmp+"</font>";break;
         case 23:case 24:case 25:tmp=zycol[6]+tmp+"</font>";break;
         case 26:case 27:case 28:tmp=zycol[7]+tmp+"</font>";break;
         case 29:case 30:case 31:tmp=zycol[8]+tmp+"</font>";break;
         case 32:case 33:case 34:tmp=zycol[9]+tmp+"</font>";break;
         case 35:case 37:case 38:tmp=zycol[9]+tmp+"</font>";break;
     }

    return tmp;
}

void Widget::calu()
{
    QStringList zym;

    zym<<"<font color=darkred>血迪凯</font> <font color=darkred>邪迪凯</font> <font color=orange>猫德</font> <font color=orange>熊德</font> <font color=lightgreen>酒仙</font> <font color=pink>防骑</font> <font color=brown>防战</font>"<<"<font color=lightgreen>酒仙</font>"<<"<font color=darkred>冰迪凯</font> <font color=pink>防骑</font>"<<"<font color=orange>猫德</font> <font color=orange>熊德</font> <font color=darkgreen>兽王猎</font> <font color=lightgreen>酒仙</font> <font color=lightgreen>风僧</font> <font color=brown>武器战</font> <font color=brown>防战</font>"<<"<font color=darkred>三系迪凯</font> <font color=darkgreen>兽王猎</font> <font color=brown>武器战</font> <font color=brown>防战</font>"
                  <<"<font color=darkred>三系迪凯</font> <font color=lightgreen>风僧</font> <font color=pink>防骑</font> <font color=brown>武器战</font> <font color=brown>防战</font>"<<"<font color=orange>熊德</font> <font color=darkgreen>兽王猎</font> <font color=lightgreen>酒仙</font> <font color=lightgreen>风僧</font> <font color=pink>防骑</font>"<<"<font color=darkred>三系迪凯</font> <font color=orange>鸟德</font> <font color=orange>熊德</font> <font color=darkgreen>兽王猎</font> <font color=lightgreen>风僧</font> <font color=brown>武器战</font>"
                 <<"<font color=lightgreen>酒仙</font>"<<"<font color=pink>防骑</font>"<<"<font color=orange>猫德</font> <font color=orange>熊德</font> <font color=darkgreen>生存猎</font> <font color=lightgreen>酒仙</font> <font color=yellow>刺杀贼</font> <font color=yellow>敏锐贼</font> <font color=brown>狂暴战</font> <font color=brown>防战</font>"<<"<font color=darkred>血迪凯</font> <font color=darkred>邪迪凯</font> <font color=darkgreen>生存猎</font> <font color=lightblue>冰法</font> <font color=pink>惩戒骑</font> <font color=yellow>敏锐贼</font> <font color=purple>恶魔术</font> <font color=brown>狂暴战</font> <font color=brown>防战</font>"
                <<"<font color=darkred>血迪凯</font> <font color=darkred>邪迪凯</font> <font color=lightblue>冰法</font> <font color=pink>防骑</font> <font color=pink>惩戒骑</font> <font color=yellow>刺杀贼</font> <font color=yellow>敏锐贼</font> <font color=purple>恶魔术</font> <font color=brown>狂暴战</font> <font color=brown>防战</font>"<<"<font color=orange>熊德</font> <font color=darkgreen>生存猎</font> <font color=lightblue>冰法</font> <font color=lightgreen>酒仙</font> <font color=pink>防骑</font> <font color=pink>惩戒骑</font> <font color=yellow>刺杀贼</font> <font color=yellow>敏锐贼</font>"
                <<"<font color=darkred>血迪凯</font> <font color=darkred>邪迪凯</font> <font color=orange>猫德</font> <font color=orange>熊德</font> <font color=darkgreen>生存猎</font> <font color=lightblue>冰法</font> <font color=pink>惩戒骑</font> <font color=yellow>刺杀贼</font> <font color=purple>恶魔术</font> <font color=brown>狂暴战</font>"<<"<font color=orange>奶德</font> <font color=lightgreen>奶僧</font> <font color=pink>奶骑</font> <font color=white>戒律牧</font> <font color=white>神牧</font> <font color=darkblue>奶萨</font>"<<"<font color=lightgreen>酒仙</font> <font color=lightgreen>奶僧</font> <font color=white>戒律牧</font> <font color=white>神牧</font> <font color=darkblue>增强萨</font>"
                <<"<font color=orange>奶德</font> <font color=white>神牧</font> <font color=darkblue>三系萨满</font>"<<"<font color=lightgreen>奶僧</font> <font color=pink>奶骑</font> <font color=darkblue>元素萨</font> <font color=darkblue>奶萨</font> <font color=purple>毁灭术</font>"<<"<font color=orange>奶德</font> <font color=lightgreen>酒仙</font> <font color=pink>奶骑</font> <font color=white>戒律牧</font> <font color=darkblue>元素萨</font> <font color=darkblue>增强萨</font> <font color=purple>毁灭术</font>"<<"<font color=orange>奶德</font> <font color=lightgreen>奶僧</font> <font color=pink>奶骑</font> <font color=white>戒律牧</font> <font color=white>神牧</font> <font color=darkblue>三系萨满</font> <font color=purple>毁灭术</font>"
                <<"<font color=lightgreen>奶僧</font> <font color=white>三系牧师</font>"<<"<font color=darkred>冰迪凯</font> <font color=orange>奶德</font> <font color=white>神牧</font> <font color=white>暗牧</font> <font color=darkblue>奶萨</font> <font color=purple>痛苦术</font>"<<"<font color=darkred>冰迪凯</font> <font color=lightgreen>奶僧</font> <font color=pink>奶骑</font> <font color=pink>防骑</font> <font color=darkblue>奶萨</font> <font color=purple>痛苦术</font>"<<"<font color=orange>奶德</font> <font color=pink>奶骑</font> <font color=pink>防骑</font> <font color=white>戒律牧</font> <font color=white>暗牧</font> <font color=purple>痛苦术</font>"
                <<"<font color=darkred>冰迪凯</font> <font color=orange>奶德</font> <font color=lightgreen>奶僧</font> <font color=pink>奶骑</font> <font color=white>三系牧师</font> <font color=darkblue>奶萨</font> <font color=purple>痛苦术</font>"<<"<font color=orange>鸟德</font> <font color=darkgreen>三系猎人</font> <font color=lightblue>火法</font> <font color=white>神牧</font> <font color=white>暗牧</font> <font color=yellow>战斗贼</font> <font color=yellow>敏锐贼</font> <font color=darkblue>增强萨</font> <font color=brown>三系战士</font>"<<"<font color=darkgreen>射击猎</font> <font color=lightblue>奥法</font> <font color=lightblue>火法</font> <font color=lightgreen>奶僧</font> <font color=lightgreen>风僧</font> <font color=yellow>三系盗贼</font> <font color=brown>三系战士</font>"
                <<"<font color=orange>鸟德</font> <font color=orange>熊德</font> <font color=darkgreen>三系猎人</font> <font color=lightblue>奥法</font> <font color=lightblue>火法</font> <font color=lightgreen>酒仙</font> <font color=lightgreen>风僧</font> <font color=white>戒律牧</font> <font color=white>暗牧</font> <font color=yellow>三系盗贼</font> <font color=darkblue>增强萨</font>"<<"<font color=orange>鸟德</font> <font color=orange>猫德</font> <font color=orange>熊德</font> <font color=darkgreen>三系猎人</font> <font color=lightblue>奥法</font> <font color=lightblue>火法</font> <font color=lightgreen>奶僧</font> <font color=lightgreen>风僧</font> <font color=white>三系牧师</font> <font color=yellow>刺杀贼</font> <font color=yellow>战斗贼</font> <font color=darkblue>增强萨</font> <font color=brown>武器战</font> <font color=brown>狂暴战</font>"
                <<"<font color=darkred>三系迪凯</font> <font color=darkgreen>射击猎</font> <font color=lightblue>火法</font> <font color=lightblue>冰法</font> <font color=pink>惩戒骑</font> <font color=yellow>战斗贼</font> <font color=yellow>敏锐贼</font> <font color=darkblue>元素萨</font> <font color=darkblue>奶萨</font> <font color=purple>痛苦术</font> <font color=purple>恶魔术</font> <font color=brown>三系战士</font>"
                <<"<font color=orange>鸟德</font> <font color=orange>奶德</font> <font color=darkgreen>三系猎人</font> <font color=lightblue>火法</font> <font color=lightblue>冰法</font> <font color=pink>惩戒骑</font> <font color=white>暗牧</font> <font color=yellow>战斗贼</font> <font color=yellow>敏锐贼</font> <font color=darkblue>元素萨</font> <font color=darkblue>增强萨</font> <font color=purple>痛苦术</font>"
                <<"<font color=darkred>三系迪凯</font> <font color=orange>鸟德</font> <font color=orange>奶德</font> <font color=darkgreen>三系猎人</font> <font color=lightblue>火法</font> <font color=lightblue>冰法</font> <font color=pink>惩戒骑</font> <font color=white>神牧</font> <font color=white>暗牧</font> <font color=yellow>战斗贼</font> <font color=darkblue>三系萨满</font> <font color=purple>痛苦术</font> <font color=purple>恶魔术</font> <font color=brown>武器战</font> <font color=brown>狂暴战</font>"
                <<"<font color=darkgreen>射击猎</font> <font color=lightblue>三系法师</font> <font color=lightgreen>风僧</font> <font color=pink>三系骑士</font> <font color=yellow>三系盗贼</font> <font color=darkblue>元素萨</font> <font color=purple>痛苦术</font> <font color=purple>毁灭术</font>"
                <<"<font color=darkred>三系迪凯</font> <font color=darkgreen>射击猎</font> <font color=lightblue>三系法师</font> <font color=lightgreen>奶僧</font> <font color=lightgreen>风僧</font> <font color=pink>奶骑</font> <font color=pink>惩戒骑</font> <font color=yellow>刺杀贼</font> <font color=yellow>战斗贼</font> <font color=darkblue>元素萨</font> <font color=darkblue>奶萨</font> <font color=purple>三系术士</font> <font color=brown>武器战</font> <font color=brown>狂暴战</font>"
                <<"<font color=orange>鸟德</font> <font color=orange>熊德</font> <font color=orange>奶德</font> <font color=darkgreen>三系猎人</font> <font color=lightblue>三系法师</font> <font color=lightgreen>风僧</font> <font color=pink>奶骑</font> <font color=pink>惩戒骑</font> <font color=white>戒律牧</font> <font color=white>暗牧</font> <font color=yellow>刺杀贼</font> <font color=yellow>战斗贼</font> <font color=darkblue>元素萨</font> <font color=darkblue>增强萨</font> <font color=purple>痛苦术</font> <font color=purple>毁灭术</font>"
                <<"<font color=orange>鸟德</font> <font color=orange>猫德</font> <font color=lightblue>奥法</font> <font color=purple>毁灭术</font> <font color=purple>恶魔术</font>"<<"无";



    int map[10]={0,0,8,15,21,26,30,33,35};
    QStringList jnm;
    jnm<<""<<"野外生物入侵"<<"重击"<<"群体伤害"<<"魔法减益"<<"危险区域"<<"爪牙围攻"<<"强力法术"<<"致命爪牙"<<"限时战斗";
    QString jnzh[40];
    bool hav[40];
    int n=0;
    for(int i=1;i<jnm.size();i++)
    {
        for(int j=i+1;j<jnm.size();j++)
        {
            jnzh[n]=jnm[i]+"+"+jnm[j]+":";
            hav[n++]=false;
        }
    }
    jnzh[n]="限时战斗+限时战斗：";
    hav[n++]=false;
    jnzh[n]="未满级：";
    hav[n++]=false;
    QString content=text->toPlainText();
    QString cmd="";
    QString name;
    int pinzhi;
    int jn1,jn2,tmp,res;
    int chongfu=0;
    QStringList words;
    int i;
    for(i=0;i<n;i++)
        jnzh[i]="<font color=white><b>"+jnzh[i]+"</b></font>";
    for(i=0;i<content.size();i++)
    {
        if(content[i]=='\n')
            break;
    }
    i++;
    for(;i<content.size();i++)
    {
        if(content[i]=='\n')
        {
            words=cmd.split(",");
            cmd="";
            name=Tf(words[1],words[3].toInt());
            if(words[8]=="0")name="<u>"+name+"</u>";
            pinzhi=words[5].toInt();
            if(pinzhi!=4)
            {
                hav[37]=true;
                jnzh[37]+=" "+name;
            }
            else
            {
                jn1=words[9].toInt();if(jn1>5)jn1--;
                jn2=words[11].toInt();if(jn2>5)jn2--;
                if(jn1>jn2)
                {
                    tmp=jn1;
                    jn1=jn2;
                    jn2=tmp;
                }
                if(jn1==jn2)
                {
                    if(hav[36])chongfu++;
                    hav[36]=true;
                    jnzh[36]+=" "+name;
                }
                else
                {
                    res=map[jn1]+(jn2-jn1)-1;
                    if(hav[res])chongfu++;
                    hav[res]=true;
                    jnzh[res]+=" "+name;
                }
            }
        }
        else
        {
            cmd+=content[i];
        }
    }
    cmd="";
    int count=0;
    for(i=0;i<38;i++)
    {
        if(hav[i])
        {
            cmd+=jnzh[i]+"<br>";
            if(i!=37)
                count++;
         }
        else
        {
            jnzh[i].replace("white","red");
            cmd+=jnzh[i]+zym[i]+"<br>";
        }
    }
    cmd="<h2><font color=white><b><i>37金刚完成："+QString::number(count)+"     其中重复随从有："+QString::number(chongfu)+"</h2></i></b></font>"+"<br>"+cmd;
   QMessageBox mes(QMessageBox::NoIcon,tr("分析结果"),cmd);
   mes.setStyleSheet("background-color: black;");
   mes.exec();

}
