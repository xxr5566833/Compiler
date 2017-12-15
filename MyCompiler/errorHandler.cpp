#include "Compiler.h"

//一些错误输出语句的说明

const char *SQMISMATCHMSG = "\' 无法匹配";

const char *DQMISMATCHMSG = "\" 无法匹配";

const char *INVALIDCHARMSG = "\'和\'中包围的字符不符合文法的规定范围，文法规定字符的范围仅限于①加法运算符②乘法运算符③字母④数字";

const char *ONLYEMMSG = "!后面没有出现=";

const char *INVALIDVTMSG = "出现了文法规定以外的非终结符！";


const char *NOTUNSIGNEDINTMSG = "应该是一个非0的无符号整数！";

const char *NOTASSIGNMSG = "应该有一个 =";

const char *NOTINTMSG = "不是一个整数";

const char *NOTIDMSG = "不是一个标识符";

const char *NOTSINGLECHARMSG = "不是一个字符";

const char *NOTINTORCHARMSG = "不是 int 或 char";

const char *NOTSEMIMSG = "不是一个分号;";

const char *NOTRBRACKETMSG = "不是一个 右中括号] ";

const char *NOTRPARENTMSG = "不是一个 右小括号)";

const char *NOTFACTORMSG = "不是一个 <因子>的开始单词 ，即不是<标识符> ( + - <字符> 0 或 无符号整数 其中之一";

const char *NOTLBRACEMSG = "不是一个 左大括号{";

const char *NOTMAINMSG = "不是 main保留字";

const char *NOTLPARENTMSG = "不是 左小括号(";

const char *NOTSTATEMENTMSG = "不是 一条语句";

const char *NOTELSEMSG = "缺少 else";

const char *NOTCONSTANTMSG = "不是 常量";

const char *NOTCOLONMSG = "不是 冒号:";

const char *NOTCASEMSG = "缺少 case";

const char *NOTRBRACEMSG = "缺少 右大括号}";

const char *NOTVARDEFMSG = "不是变量定义的正确符号 [ ; 或 ,";

//语义：

const char *DUPLICATEDEFMSG = "标识符重复定义！";

const char *PARATYPEDISMATCHMSG = "值参类型与形参类型不一致!";

const char *PARANUMDISMATCHMSG = "值参和形参的数量不一致";

const char *IDNOTDEFMSG = "标识符未定义";

const char *NOTAINTMSG = "不是一个int型表达式";

const char *NOTANARRAYMSG = "不是一个数组类型的标识符";

const char *NOTAFUNCMSG = "标识符不是一个函数名";

const char *NOTANOPARAFUNCMSG = "不是一个无参的函数";

const char *INVALIDIDMSG = "不是一个被正确使用的标识符";

const char *NOTASIMPLEMSG = "不是一个简单变量标识符";

const char *CASESWITCHDISMATCHMSG = "case语句的常量类型和switch语句的表达式类型不一致！";

const char *NONERETURNMSG = "有返回值类型的函数没有一句return。";

const char *CANNOTRETURNMSG = "void不能return 一个实际的值";

const char *RETURNTYPEDISMATCHMSG = "return的类型和函数定义时的类型不一致";

const char *INTTOCHARNOTALLOWMSG = "不允许从把int类型赋给char类型！";

const char *NORETURNVALUEMSG = "不是一个有返回值的函数";

const char *CASEVALUEDUPLICATEMSG = "case后的常量出现了重复";

const char *ARRAYINDEXOUTOFRANGEMSG = "数组下标越界！";

const char *DIVZEROMSG = "不能除以0";
 
void Compiler:: errorHandle(errorType id)
{
	//std::cout << this->sym << std::endl;
	error *err = new error();
	err->id = id;
	err->lineCount = this->lineCount;
	err->token = new std::string(this->sym);

	this->errorList.push_back(err);
}

void Compiler:: errorSetup()
{
	//词法分析
	this->errorMsgList[SQMISMATCH]			=	new std::string(SQMISMATCHMSG);
	this->errorMsgList[DQMISMATCH]			=	new std::string(DQMISMATCHMSG);
	this->errorMsgList[INVALIDCHAR]			=	new std::string(INVALIDCHARMSG);
	this->errorMsgList[ONLYEM]				=	new std::string(ONLYEMMSG);
	this->errorMsgList[INVALIDVT]			=	new std::string(INVALIDVTMSG);

	//语法分析
	this->errorMsgList[NOTUNSIGNEDINT]		=	new std::string(NOTUNSIGNEDINTMSG);
	this->errorMsgList[NOTASSIGN]			=	new std::string(NOTASSIGNMSG);
	this->errorMsgList[NOTINT]				=	new std::string(NOTINTMSG);
	this->errorMsgList[NOTID]				=	new std::string(NOTIDMSG);
	this->errorMsgList[NOTSINGLECHAR]		=	new std::string(NOTSINGLECHARMSG);
	this->errorMsgList[NOTINTORCHAR]		=	new std::string(NOTINTORCHARMSG);
	this->errorMsgList[NOTSEMI]				=	new std::string(NOTSEMIMSG);
	this->errorMsgList[NOTRBRACKET]			=	new std::string(NOTRBRACKETMSG);
	this->errorMsgList[NOTRPARENT]			=	new std::string(NOTRPARENTMSG);
	this->errorMsgList[NOTFACTOR]			=	new std::string(NOTFACTORMSG);
	this->errorMsgList[NOTLBRACE]			=	new std::string(NOTLBRACEMSG);
	this->errorMsgList[NOTMAIN]				=	new std::string(NOTMAINMSG);
	this->errorMsgList[NOTLPARENT]			=	new std::string(NOTLPARENTMSG);
	this->errorMsgList[NOTSTATEMENT]		=	new std::string(NOTSTATEMENTMSG);
	this->errorMsgList[NOTELSE]				=	new std::string(NOTELSEMSG);	
	this->errorMsgList[NOTCONSTANT]			=	new std::string(NOTCONSTANTMSG);
	this->errorMsgList[NOTCOLON]			=	new std::string(NOTCOLONMSG);
	this->errorMsgList[NOTCASE]				=	new std::string(NOTCASEMSG);
	this->errorMsgList[NOTRBRACE]			=	new std::string(NOTRBRACEMSG);
	this->errorMsgList[NOTVARDEF]			=	new std::string(NOTVARDEFMSG);
	
	//语义和符号表：
	this->errorMsgList[DUPLICATEDEF]		=	new std::string(DUPLICATEDEFMSG);
	this->errorMsgList[PARATYPEDISMATCH]	=	new std::string(PARATYPEDISMATCHMSG);
	this->errorMsgList[PARANUMDISMATCH]		=	new std::string(PARANUMDISMATCHMSG);
	this->errorMsgList[IDNOTDEF]			=	new std::string(IDNOTDEFMSG);
	this->errorMsgList[NOTAINT]				=	new std::string(NOTAINTMSG);
	this->errorMsgList[NOTANARRAY]			=	new std::string(NOTANARRAYMSG);	
	this->errorMsgList[NOTAFUNC]			=	new std::string(NOTAFUNCMSG);
	this->errorMsgList[NOTANOPARAFUNC]		=	new std::string(NOTANOPARAFUNCMSG);
	this->errorMsgList[INVALIDID]			=	new std::string(INVALIDIDMSG);
	this->errorMsgList[NOTASIMPLE]			=	new std::string(NOTASIMPLEMSG);
	this->errorMsgList[CASESWITCHDISMATCH]	=	new std::string(CASESWITCHDISMATCHMSG);
	this->errorMsgList[NONERETURN]			=	new std::string(NONERETURNMSG);
	this->errorMsgList[RETURNTYPEDISMATCH]	=	new std::string(RETURNTYPEDISMATCHMSG);
	this->errorMsgList[INTTOCHARNOTALLOW]	=	new std::string(INTTOCHARNOTALLOWMSG);
	this->errorMsgList[NORETURNVALUE]		=	new std::string(NORETURNVALUEMSG);
	this->errorMsgList[CASEVALUEDUPLICATE]	=	new std::string(CASEVALUEDUPLICATEMSG);
	this->errorMsgList[ARRAYINDEXOUTOFRANGE]=	new std::string(ARRAYINDEXOUTOFRANGEMSG);
	this->errorMsgList[DIVZERO]				=	new std::string(DIVZEROMSG);
}

void Compiler:: errorPrint()
{
	this->errorSetup();
	int s = this->errorList.size();
	for(unsigned int i = 0; i < this->errorList.size(); ++i)
	{
		error *err = errorList[i];
		std::stringstream msg = std::stringstream();
		msg << "line:" << err->lineCount << "\t" << "在" << *err->token << "的附近:" << *(this->errorMsgList[err->id]) << "\n";
		std::cout << msg.str() ;
	}
}