

#define STUDENT ElementType
#define Average key          //把平均成绩作为了查找、删除关键字 
struct STUDENT
{
	int 	No;		//学号
	char 	Name[10];//	姓名
	float 	CPMark;//计算机基础
	float 	DSMark;	//数据结构
	float 	PGMark;//程序设计
	float 	Average;//平均成绩
};