#pragma once
#include "stdafx.h"
#include "token.h"
#include "errorHandler.h"
#include "warningHandler.h"
#include "symbolTab.h"
#include "midcode.h"
#include "objectCode.h"
#include "optimization.h"
//������ֿռ�
const int kMaxReserve = 100;
//��󵥴������ռ�
const int kMaxWord = 100;
//�����ű�ռ�
const int kMaxSymbol = 5000;
//�ֺ��������ű�ռ�
const int kMaxFuncSymbol = 500;
//����ж��ٸ�����
const int kMaxFuncNum = 500;
//hash�������ֵ
const int kMaxHash = 4096;
//���������ĸ������ֵ
const int kMaxParaNum = 20;
//��Ԫʽ�������
const int kMaxMidCode = 5000;
//������ַ�����
const int kMaxStringNum = 1000;
//�������������
const int kMaxBasicBlock = 1000;
//�����ʱ����������
const int kMaxTemp = 1000;

//��ʶ��������  ������ֿ�
enum eRetType {INTRET = 7, CHARRET, VOIDRET, NOTTYPE };
//��ʶ�������࣬�ֱ��ǳ������򵥱����������������������ʽ��������
enum eSymType {CONSTSYM, SIMPLESYM, ARRAYSYM, FUNCSYM, PARASYM};


typedef struct 
{
	std::string *name;
	//C++��ö�����Ͳ�����Ϊ������������ֻ����int����ʾ
	eRetType returnType;
	eSymType symbolType;
	//�������飬����ʾ����ĳ��ȣ����ں���������ʾ�����ĸ��������ڳ���������ʾ���������ֵ�����ڱ���������ʽ�������߾ֲ�������Ŀǰ����Ϊ-1
	int feature;
	//���ں�����ref��¼�����ڷֺ������е�λ��,��Ȼmainû�����ref
	int ref;
	//��¼�����������������ڱ���͵���
	int decLine;
	//��¼��ʹ�õ����������ڱ���͵���
	std::vector<int> *useLine;
	//��Ϊʹ��hash�������������������¼��ͻ���λ�ã�Ĭ��Ϊ-1
	int link;
	//���ں���������Ҫ������Ĳ����ĸ��������ͣ���������ר�Ÿ�������һ�����飬�涨����������
	eRetType paraList[kMaxParaNum];
	//�����ĵ�ַ
	int address;
}symbol;

unsigned int BKDRHash(char *str);

class Compiler
{
public:
	Compiler(char *path);
	void begin();
	//��ӡ��ǰ���ű���Ϣ�����ڵ���
	void printSymTab();
	//�������� int to string
	void int2string(std::string *s, int value);
	//ͳһת��ΪСд
	void str2Lower(std::string *oldstr, std::string *newstr);
	~Compiler();

private:
	//�ļ���ָ��
	std::fstream file;
	//��ǰ�ַ�
	char c;
	//��ǰ������ַ�����
	std::string sym;
	//inSym()ִ�к󣬱���ĵ�ǰ ����
	token tok;
	//��ǰ����
	int lineCount ;

	//�����ּ��ϣ���ΪҪ�Ƚ��ǲ��Ǳ����ֱ���Ҫһ�����ַ����бȽ�
	std::string reserve[kMaxReserve];
	//���ʱ�־������飬��ö������һһ��Ӧ
	std::string wordOutput[kMaxWord];

	//��ʼ��
	void initWordArray();
	void setup();

	//��������йص�
	void skip();

	//��sym�йص�
	void clearSym();
	void symAppend();
	void inSym();

	bool isEof();
	void nextChar();
	void retract();

	//����������
	void skipSpace();


	//��һ��
	void readUntilNotLetterOrNum();

	//�ж�
	//�жϵ����ַ�
	bool isSpace();
	bool isTab();
	bool isNewLine();
	bool isSq();
	bool isDq();
	bool isZero();
	bool isLess();
	bool isMore();
	bool isEqu();
	//Em��ʾ��̾��
	bool isEm();

	bool isLetter();
	bool isNumber();
	bool isPlusOrMinus();
	bool isStarOrDiv();

	bool isInStringRange();

	//�жϱ�ʶ�����߱������Ƿ����
	bool isIdEqual(std::string id1, std::string id2);
	//����sym
	void handleSym();


	//�﷨������أ�
	//�ж�
	bool isInRange(const tokenType range[], int size);
	//�﷨�ɷ֣�
	void int_(int *value);
	void constDef();
	void constState();
	void constant(int *value, eRetType *rettype);
	void varParaList(symbol *sym);
	void factor(eRetType *resulttype, std::string *operand);
	void term(eRetType *resulttype, std::string *operand);
	void expression(eRetType *type, std::string *operand);
	void varDef(eRetType rettype, std::string *name);
	void decHead(eRetType *rettype, std::string **name);
	void para(symbol *sym);
	void noParaFuncDef(symbol *sym);
	void haveParaFuncDef(symbol *sym);
	void notMainVoidFuncDef();
	void mainDef();
	void beginWithFunc();
	void beginWithVar();
	void program();
	void condition(std::string *label);
	void ifStatement(bool *returnflag, eRetType returntype, std::string *name);
	void caseStatement(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *nextlab, int *caseconst, std::string *name);
	void caseTab(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *name);
	void switchStatement(bool *returnflag, eRetType returntype, std::string *name);
	void whileStatement(bool *returnflag, eRetType returntype, std::string *name);
	void scanfStatement();
	void printfStatement();
	void returnStatement(bool *returnflag, eRetType returntype, std::string *name);
	void statement(bool *returnflag, eRetType returntype, std::string *name);
	void statementList(bool *returnflag, eRetType returntype, std::string *name);
	void varState();
	void comStatement(bool *returnflag, eRetType returntype, std::string *name);

	//�������
	std::vector<error*> errorList;
	std::string *errorMsgList[kMaxErrorType];
	void errorHandle(errorType errodId);
	void errorSetup();
	void errorPrint();
	//����
	void errorSkip(tokenType id);

	//������
	std::vector<warning*> warningList;
	std::string *warningMsgList[kMaxWarningType];
	void warningHandle(warningType warningId);
	void warningSetup();
	void warningPrint();

	//���ű����
	symbol *symTab[kMaxSymbol];
	int symHash[kMaxHash];
	//�ֳ�������
	int index;
	//ָʾ��ǰ���ű�ĵ�һ������λ��
	int top;
	//ָʾ��ǰ����/�����ô洢��λ��
	int address;
	//����ȫ�ֱ����������ķ������
	int globalAddress;

	void initSymTab();
	//����,����local�����Ǿֲ����һ���ȫ�ֲ���
	bool find(std::string *name, symbol **sym, bool local);
	//����
	symbol* push(std::string *name, eRetType returntype, eSymType symboltype, int feature, int decline);

	//ɾ�����ű�ֱ��this->index��ǰһ������ά��this->index this->top��ע���ͷſռ�,��Ҫά��hash��
	void pop();
	//Ϊ���Ժ��������Ŀ����룬�������Ҫ�ѱ�����ĺ����ķ�����Ϣ��¼����
	symbol **funcSymTab[kMaxFuncSymbol];
	//��¼������ķֺ����ķ��Ÿ���������ֺ�������������main
	int funcSymNum[kMaxFuncNum];
	//��¼�ֺ�������������ַ
	int funcMaxAddress[kMaxFuncNum];
	//��¼�ж��ٸ��ֺ���
	int funcNum;
	//��¼��ǰ�ֺ����ķ��Ÿ���
	int currentFuncSymNum;
	//��ӡһ������
	void printSym(symbol *sym);
	//����һ������ʱ
	void inFunc();

	//������
	std::string *stringTab[kMaxStringNum];
	int stringNum ;
	//��Ҫһ�������¼���е��ַ��������ƫ��,���������.asciiz�Ļ�����ʱ������ַ������±꣬�õ�����ʼ��ֱַ�����Ҳ����
	int stringAddress[kMaxStringNum];
	//��Ҫһ������¼�ַ���ռ���˶��ٿռ�
	int strAddress;
	void pushString(std::string *str);
	void genMessage(std::string *str, int num);

	//��Ԫʽ���
	void writeMidCode(midcode *code, bool stdflag, bool fileflag, bool optimize);
	//��Ԫʽ�ļ�
	std::fstream midFile;
	//��Ԫʽ����
	midcode* codes[kMaxMidCode];
	//����ָ��
	int midindex;
	//����һ����Ԫʽ
	void pushMidCode(midop op, std::string *operand1, std::string *operand2, std::string *rst, bool optimize);
	//init
	void initMidCode();
	//label����ʱ������Ҫ�и����ɺ���,���ҷֱ��и���������������ά��
	void genTemp(std::string *temp);
	int temp;
	void genLabel(std::string *lab);
	int label;

	//�Ż�����Ԫʽ���ļ�
	std::fstream optimizeFile;
	//�Ż�����Ԫʽ����
	midcode* optimizeCodes[kMaxMidCode];
	int optimizeMidIndex;

	//�Ż����
	void divideToBlock();
	//�Ż�һ��ʼ�ĳ�ʼ��
	void initOptimize();
	void printBlock();
	void findNodeInTab(ListNode *nodelist[], int length, std::string *name, ListNode **x);
	void smallOptimize();
	bool canAdd(bool flag[], Node *x);
	void DAG();
	int blockBegin[kMaxBasicBlock];
	int blockIndex;
	int tempMap[kMaxTemp];


	//Ŀ���������
	std::fstream objectFile;
	//��ʼ���Ĵ�����
	void objectInit();
	//��ʼ���ַ�������
	void initAscii();
	//����Ŀ�����
	void generate();
	//��ȫ�ֳ���
	void initConstAndVar(symbol *sym, int initaddress);
	//��ǰռ�õĿռ�
	int mipsAddress;
	//����һ��ָ��
	void generateOrder(std::string *order, std::string *rd, std::string *rs, std::string *rt);
	void generateOrder(std::string *order, std::string *rs, int baseaddress, std::string *rt);
	void generateOrder(std::string *order, std::string *rs, int num);
	void generateOrder(std::string *order, std::string *rd, std::string *rt, int imme);
	void generateOrder(std::string *order, std::string *rs, std::string *label);
	void generateOrder(std::string *order, std::string *target);
	void generateOrder(std::string *order);
	//�����Ŀ�ʼ
	void funcBegin(std::string *name);
	//��ֵ
	void handleAssign(midcode *code);
	//��ǰ����ĺ����ں������е�λ��
	int currentRef;
	//����label
	void genMipsLabel(std::string *label);
	//Ѱ�ұ�ʶ����ַ
	void findAddress(std::string *name, int *offset, bool *global);
	//loadword
	void loadWord(std::string *rs, std::string *reg);
	//storeword
	void storeWord(std::string *rd);
	//������
	void handleNeg(midcode *code);
	//������ת
	void handleBranch(midcode *code);
	//������������ת
	void handleGoto(std::string *label);
	//����ʵ��
	void handleRealPara(std::string *para);
	//�������鸳������ֵ
	void handleRarray(midcode *code);
	//����������
	void handleCall(std::string *name);
	//����������
	void handleRet(std::string *name);
	//��������
	void handleCompute(midcode *code);
	//��������
	void handleScanf(midcode *code);
	//�������
	void handlePrintf(midcode *code);
	//�������
	void handleExit();
	//��������ֵ������
	void handleLarray(midcode *code);

	//�жϲ�����������
	//�ж�����������ǲ���һ������(- ������ ���ֿ�ͷ)
	bool isOperandNumber(std::string *operand);
	//�ж�����������ǲ���һ����ʱ����
	bool isOperandTemp(std::string *operand);
	//�ж�����������ǲ���һ������ֵ
	bool isOperandRet(std::string *operand);
	//�ж��ǲ���һ����ʶ��
	bool isOperandId(std::string *operand);

	//�Ĵ����򵥷���
	//9����ʱ�Ĵ������ֱ����t0��t8,-1��ʾδ����
	int tempReg[8];
	int tempRegIndex ;
	//8��Ϊ��ʶ��׼���ļĴ������ֱ����s0��s7,ֵΪ0��ʾû�б����䣬ֵ��Ϊ0����ʾ��������ֵı�ʶ������
	std::string *symReg[8];
	int symRegIndex;
	void allocReg(std::string *operand, std::string *reg);
	regAllocStack regStack;
	void stackPop();
	void stackPush();



	


};

