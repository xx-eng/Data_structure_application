

#define HEADSTUDENT	HeadType 	
#define STUDENT		ElementType		//ʵ������Ԫ�ؾ����

class HEADSTUDENT				//ʵ������Ԫ�ر�ͷ���͵Ķ���
{
public:
	char		nameclass[20];
	int			number;
	char		place[20];
};

class STUDENT					//ʵ������Ԫ�����͵Ķ���
{
public:
	char			number[8];
	char			name[20];
	char			sex[3];
	int				age;
};