

#define HEADSTUDENT	HeadType 	
#define STUDENT		ElementType		//实例数据元素句柄化

class HEADSTUDENT				//实例数据元素表头类型的定义
{
public:
	char		nameclass[20];
	int			number;
	char		place[20];
};

class STUDENT					//实例数据元素类型的定义
{
public:
	char			number[8];
	char			name[20];
	char			sex[3];
	int				age;
};