#include "mysyntaxhighlighter.h"

MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
}
void MySyntaxHighlighter::highlightBlock(const QString &text)//高亮文本块
{
    QTextCharFormat myFormat;//字符格式
    myFormat.setFontWeight(QFont::Bold);
    myFormat.setForeground(Qt::green);
    QString pattern="\\b\\d+\\b";//要匹配的字符char
    QRegExp exp(pattern);//创建正则表达式
    int index=text.indexOf(exp);//从位置0开始匹配
    //匹配成功返回字符串的起始位置值
    while(index>=0)
    {
        int length=exp.matchedLength();//要匹配字符串的长度
        setFormat(index,length,myFormat);//对咬匹配的字符串设置格式
        index=text.indexOf(exp,index+length);//继续匹配
    }
}
