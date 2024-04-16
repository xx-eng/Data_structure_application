#define MAP  ElementType         //实例元素句柄化
#define AreaIndex key            //实例元素关键字句柄化

struct MAP
{
	int AreaIndex;           //地区编号
	char AreaName[20];       //地区名称
	int ColorIndex;          //颜色编号
};


class StackType
{
public:
	int AreaIndex;         //地区编号
	int ColorIndex;        //颜色编号
};
