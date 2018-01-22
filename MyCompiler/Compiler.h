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
const int kMaxFuncSymbol = 1000;
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
const int kMaxBasicBlock = 2000;
//�����ʱ����������
const int kMaxTemp = 1000;
//���Ŀ���������
const int kMaxMipsCodes = 10000;

//��ʶ��������  ������ֿ�
enum eRetType {INTRET = 7, CHARRET, VOIDRET, NOTTYPE };
//��ʶ�������࣬�ֱ��ǳ������򵥱����������������������������
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
	//��Ϊʹ��hash�������������������¼��ͻ���λ�ã�Ĭ��Ϊ-1
	int link;
	//���ں���������Ҫ������Ĳ����ĸ��������ͣ���������ר�Ÿ�������һ�����飬�涨����������
	eRetType paraList[kMaxParaNum];
	//�����ĵ�ַ
	int address;
	//��¼������ֲ����������������ÿ�����������ʹ�����
	bool flag[kMaxBasicBlock];
	//��¼�������ʶ����Ӧ�ļĴ�������������ʱ�����ͼ򵥱����Լ�����������Ч
	int regIndex;
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
	/*------------�ʷ��������------------*/
	//�ļ���ָ��
	std::fstream file;
	//��ǰ�ַ�
	char c;
	//����һ���ַ�
	void nextChar();
	//���ļ�ָ����һ�ζ����ĵ��ʻ��ǵ�ǰ������ʣ���ά�����������ַ�����
	void retract();
	//��ǰ������ַ�����
	std::string sym;
	//����ĵ�ǰ,����,���嶨���token.h
	token tok;
	//��ǰ����
	int lineCount ;
	//�ж��ļ��Ƿ����
	bool isEof();



	//�����ּ��ϣ���ΪҪ�Ƚ��ǲ��Ǳ����ֱ���Ҫһ�����ַ����бȽ�
	std::string reserve[kMaxReserve];
	//���ʱ�־������飬��ö������һһ��Ӧ
	std::string wordOutput[kMaxWord];
	////��ʼ���������͵�string�������ö��һһ��Ӧ����Ҫ����һ��ʼ�Ĵʷ������ĵ��������֮��û��ʵ������
	void initWordArray();
	//���������ֱ����ڵõ���ǰ�����ǲ���һ��������
	void setup();
	//��sym�йص�
	//���sym�ַ��������������µĵ���
	void clearSym();
	//�ѵ�ǰ�ַ���ӵ���ǰ�ַ�������
	void symAppend();
	//��ʾ����һ���µĵ��ʣ�������tok�У�Ϊ�﷨������ʹ��
	void inSym();
	//�ʷ�����������Ҫ�õ����жϣ�
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
	//�жϵ�ǰ�ַ��Ƿ��ڸ������ķ���Χ��
	bool isInStringRange();

	//�жϱ�ʶ�����߱������Ƿ����
	bool isIdEqual(std::string id1, std::string id2);
	//ר�����ڴ���ǰ�Ǳ����ֻ��Ǳ�ʶ��
	void handleSym();

	//�����հ��ַ�������ע��ά��lineCount
	void skipSpace();



	/*----------------�﷨�������----------------*/
	//�﷨�ɷ֣�
	//<����>
	void int_(int *value);
	//<��������>
	void constDef();
	//<��������>
	void constState();
	//<����>
	void constant(int *value, eRetType *rettype);
	//<������>
	void varParaList(symbol *sym);
	//<����>
	void factor(eRetType *resulttype, std::string *operand);
	//<��>
	void term(eRetType *resulttype, std::string *operand);
	//<���ʽ>
	void expression(eRetType *type, std::string *operand);
	//<�������崦��>
	void varDef(eRetType rettype, std::string *name);
	//<����ͷ��>
	void decHead(eRetType *rettype, std::string **name);
	//<����>
	void para(symbol *sym);
	//<�޲κ�������>
	void noParaFuncDef(symbol *sym);
	//<�вκ�������>
	void haveParaFuncDef(symbol *sym);
	//<��main��void���͵ĺ�������>
	void notMainVoidFuncDef();
	//<main��������>
	void mainDef();
	//<�����Ժ������忪ʼ�ĳ���>
	void beginWithFunc();
	//<�����Ա���������ʼ�ĳ���>
	void beginWithVar();
	//<����>
	void program();
	//<����>
	void condition(std::string *label);
	//<�������>
	void ifStatement(bool *returnflag, eRetType returntype, std::string *name);
	//<��������>
	void caseStatement(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *nextlab, int *caseconst, std::string *name);
	//<�����>
	void caseTab(eRetType switchtype, std::string *switchtemp, bool *returnflag, eRetType returntype, std::string *donelab, std::string *name);
	//<������>
	void switchStatement(bool *returnflag, eRetType returntype, std::string *name);
	//<ѭ�����>
	void whileStatement(bool *returnflag, eRetType returntype, std::string *name);
	//<�����>
	void scanfStatement();
	//<д���>
	void printfStatement();
	//<�������>
	void returnStatement(bool *returnflag, eRetType returntype, std::string *name);
	//<���>
	void statement(bool *returnflag, eRetType returntype, std::string *name);
	//<�����>
	void statementList(bool *returnflag, eRetType returntype, std::string *name);
	//<��������>
	void varState();
	//<�������>
	void comStatement(bool *returnflag, eRetType returntype, std::string *name);

	//�жϵ����Ƿ��ڸ����ķ�Χ��
	bool isInRange(const tokenType range[], const int size);




	/*-----------------���������-----------------*/
	//�������
	std::vector<error*> errorList;
	std::string *errorMsgList[kMaxErrorType];
	void errorHandle(errorType errodId);
	void errorSetup();
	void errorPrint();
	//����
	void skip(const tokenType follow[], const int size);
	void skip(tokenType toktype);
	//���ݴ������������
	void errorSkip(errorType id);
	//������
	std::vector<warning*> warningList;
	std::string *warningMsgList[kMaxWarningType];
	void warningHandle(warningType warningId);
	void warningSetup();
	void warningPrint();

	/*----------------���ű����----------------*/
	//���ű�
	symbol *symTab[kMaxSymbol];
	//hash��
	int symHash[kMaxHash];
	//�ֳ�������
	int index;
	//ָʾ��ǰ���ű�ĵ�һ������λ��
	int top;
	//ָʾ��ǰ����/�����ô洢��λ��
	int address;
	//����ȫ�ֱ����������ķ������
	int globalAddress;
	//���ű��һЩ��ʼ��
	void initSymTab();
	//����,����local�����Ǿֲ����һ���ȫ�ֲ���
	bool find(std::string *name, symbol **sym, bool local);
	//����÷���
	symbol* push(std::string *name, eRetType returntype, eSymType symboltype, int feature, int decline);

	//Ϊ���Ժ��������Ŀ����룬�������Ҫ�ѱ�����ĺ����ķ�����Ϣ��¼����
	symbol **funcSymTab[kMaxFuncSymbol];
	//��¼������ķֺ����ķ��Ÿ���
	int funcSymNum[kMaxFuncNum];
	//��¼�ֺ�������������ַ
	int funcMaxAddress[kMaxFuncNum];
	//��¼�ж��ٸ��ֺ���
	int funcNum;
	//��¼��ǰ�ֺ����ķ��Ÿ���
	int currentFuncSymNum;
	//����һ������ʱ
	void inFunc();
	//ɾ�����ű�ֱ��this->index��ǰһ������ά��this->index this->top��ע���ͷſռ�,��Ҫά��hash��
	void pop();
	//�ַ������飬��¼�����õ����ַ���
	std::string *stringTab[kMaxStringNum];
	int stringNum ;
	//��Ҫһ�������¼���е��ַ��������ƫ��,���������.asciiz�Ļ�����ʱ������ַ������±꣬�õ�����ʼ��ֱַ�����Ҳ����
	int stringAddress[kMaxStringNum];
	void pushString(std::string *str, int *strindex);
	void genMessage(std::string *str, int num);

	//��ӡһ������
	void printSym(symbol *sym);
	//���ű��ӡ�ļ�
	std::fstream symtabFile;
	//��ӡ���ű��ļ�
	void writeSymtoFile();



	/*----------------�м�������----------------*/
	//��һ���м����д��ָ�����ļ���
	void writeMidCode(midcode *code, std::fstream &tofile);
	//��һ���м�������̨���
	void writeMidCode(midcode *code);
	//��������Ԫʽд���ļ�
	void writeMidCodetoFile(std::fstream &tofile);
	//��Ԫʽ����
	midcode* codes[kMaxMidCode];
	//��Ԫʽ����
	int midindex;
	//����һ����Ԫʽ
	void pushMidCode(midop op, std::string *operand1, std::string *operand2, std::string *rst);
	//���﷨����ʱ�����м������ҪһЩ��ʼ��
	void initMidCode();
	//label����ʱ������Ҫ�и����ɺ���,���ҷֱ��и���������������ά��
	void genTemp(std::string *temp);
	int temp;
	void genLabel(std::string *lab);
	int label;
	//�Ż�ǰ��Ԫʽ�ļ�
	std::fstream midFileBefore;
	//�Ż�����Ԫʽ���ļ�
	std::fstream midFileAfter;

	/*------------------�Ż����------------------*/
	//��¼�þ���Ԫʽ�Ƿ���ĳһ��������Ŀ�ʼ������Ѿ��м�¼����ô�Ͳ�Ҫ�ظ���¼����ֹ���ֳ���Ϊ0�Ļ�����
	bool blockBeginFlag[kMaxMidCode];
	//��¼ÿ��������Ŀ�ʼ����Ԫʽ��index
	int blockBegin[kMaxBasicBlock];
	//��¼����
	int blockIndex;
	//�ֳɻ�����
	void divideToBlock();
	//��ʼ��������֮������ӹ�ϵ
	void initBlockConnect();
	//���ֻ����������������ļ�
	std::fstream blockFile;
	//��¼ÿ�����������Ϣ
	Block* blockArray[kMaxBasicBlock];
	//����label�����������ڵĻ�����index����С�Ż�ʱ���õ�
	void findLabel(std::string *label, int *index);
	//�Ż�һ��ʼ�ĳ�ʼ��
	void initOptimize();
	//�ѻ��������Ϣ������������ļ���
	void writeBlockToFile();
	//һЩС���Ż�
	void smallOptimize();

	//��������������ļ���
	std::fstream dataAnalysisFile;
	//��������������
	void dataFlowAnalysis();
	//��Ҫһ����¼ÿ�������Ļ����鿪ʼ��������ݽṹ
	int funcBlockBegin[kMaxFuncNum];
	//��Ҫһ�������õ�����ֲ������ں������е��±�
	void getIndexInTab(int *index, int funcref, std::string *name);
	void findNodeInTab(ListNode *nodelist[], int length, std::string *name, ListNode **x);
	//��������һ����Ա���������ڼ�¼ÿ���������out���ϣ�����dagͼɾȥ����Ҫ����ʱ����
	bool **outData;
	bool canAdd(bool flag[], Node *x, Node* midqueue[], int length, Node *dag[]);

	//DAGͼ����
	void DAG();
	//dagͼ�Լ�С���Ż�����Ϣ
	std::fstream dagFile;
	/*--------------------Ŀ��������--------------------*/
	//Ŀ������Ż�ǰ�ļ�
	std::fstream objectFileBefore;
	//Ŀ������Ż����ļ�
	std::fstream objectFileAfter;
	//Ŀ���������
	std::string *mipsCodes[kMaxMipsCodes];
	//�±�
	int mipsIndex;
	//��ʼ��Ŀ���������
	void objectInit();
	//��ʼ���Ĵ����أ���ʱ�Ĵ�����ֻ�Ǽ�¼��ǰʹ�øüĴ����ı�������
	void regInit();
	//��ʼ���ַ�������
	void initAscii();
	//����Ŀ�����
	void generate();
	//����һ��ָ��
	void generateOrder(std::string *order, std::string *rd, std::string *rs, std::string *rt);
	void generateOrder(std::string *order, std::string *rs, int baseaddress, std::string *rt);
	void generateOrder(std::string *order, std::string *rs, int num);
	void generateOrder(std::string *order, std::string *rd, std::string *rt, int imme);
	void generateOrder(std::string *order, std::string *rs, std::string *label);
	void generateOrder(std::string *order, std::string *target);
	void generateOrder(std::string *order);
	//���������浽Ŀ�����������
	void pushOrder(std::string *order);
	//�ѵ�ǰĿ�����д����Ӧ���ļ���
	void writeMipsOrderToFile(std::fstream &tofile);

	//������ʼ
	void funcBegin(std::string *name);
	//��ǰ����ĺ����ں������е�λ��
	int currentRef;
	//����label
	void genMipsLabel(std::string *label);
	//Ѱ�ұ�ʶ����ַ
	void findSym(std::string *name, symbol **resultsym, bool *global);
	//loadword
	void getUseReg(std::string *rs, std::string *reg);
	//storeword
	void getResultReg(std::string *rd, std::string *reg);
	//writeback
	void writeBack(std::string *rd, std::string *reg);
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
	void handleAdd(midcode *code);
	void handleSub(midcode *code);
	void handleMulOrDiv(midcode *code);

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

	//����kMaxRegAvailable �����������Ŀ��üĴ���������������ÿһ���������0����ô��ʾδ�����䣬�������0����ô��ʾ����Ӧ�ı�������
	std::string *allReg[kMaxRegAvailable];



	


};

