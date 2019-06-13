#include<iostream>
#include<cmath>

using namespace std;

#if 0			
typedef struct Cube{
	int a;
	int b;
	int c;
}Cube_t;

int get_volume(Cube_t &c)
{
	return c.a*c.b*c.c;
}
int get_area(Cube_t &c)
{
	return (2*c.a*c.b+2*c.a*c.c+2*c.c*c.b);
}

bool is_equal(Cube_t &c1, Cube_t &c2)
{
	if(c1.a==c2.a && c1.b==c2.b && c1.c==c2.c)
		return true;
	return false;
}

int main()
{
	Cube_t c1;
	Cube_t c2;
	
	c1.a = 1;c1.b = 2;c1.c = 3;
	c2.a = 4;c2.b = 2;c2.c = 3;
	
	int s_c1 = get_area(c1);
	int v_c1 = get_volume(c1);
	cout<<"c1的面积是："<<s_c1<<endl;
	cout<<"c1的体积是："<<v_c1<<endl;
	
	int s_c2 = get_area(c2);
	int v_c2 = get_volume(c2);
	cout<<"c2的面积是："<<s_c2<<endl;
	cout<<"c2的体积是："<<v_c2<<endl;
	
	if(is_equal(c1,c2))
		cout<<"两个一样"<<endl;
	cout<<"两个不一样！"<<endl;
	
	return 0;
}
#endif

#if 0
class Cube{
public:
	void set_abc(int a, int b, int c)
	{
		m_a = a; m_b = b; m_c = c;
	}
	int get_a(){return m_a;}
	int get_b(){return m_b;}
	int get_c(){return m_c;}
	
	int get_area()
	{
		return 2*(m_a*m_b+m_a*m_c+m_c*m_b);
	}
	int get_volume(){return m_a*m_b*m_c;}
	
	void judge_same(Cube &c)
	{
		if(m_a==c.get_a() && m_b==c.get_b() && m_c==c.get_c())
		{	
			cout<<"两个一样"<<endl;
			return;
		}
		cout<<"两个不一样"<<endl;
		return;
	}
	
private:
	int m_a;
	int m_b;
	int m_c;
};

int main()
{	
	Cube c1, c2;
	c1.set_abc(1,2,3);
	c2.set_abc(1,2,3);
	
	cout<<"c1的面积是："<<c1.get_area()<<endl;
	cout<<"c1的体积是："<<c1.get_volume()<<endl;
	
	cout<<"c2的面积是："<<c2.get_area()<<endl;
	cout<<"c2的体积是："<<c2.get_volume()<<endl;
	
	c1.judge_same(c2);
	
	return 0;
}
#endif

#if 0
class Point{
public:
	void set_xy(int x, int y){
		m_x=x; m_y=y;
	}
	int get_x(){return m_x;}
	int get_y(){return m_y;}
	
	void get_dist(Point &p)
	{
		int i = abs(m_x - p.get_x());
		int j = abs(m_y - p.get_y());
		cout<<"两个点之间的距离是："<< sqrt(j*j + i*i)<<endl;
		return;
	}
private:
	int m_x;
	int m_y;
};


class Circle{
public:
	void set_r(){
		int r;
		cout<<"请输入半径：";
		cin>>r;
		m_r = r;}
	void set_cir_pos(){
		int x;		int y;
		cout<<"请输入圆心坐标：";
		cin>>x>>y;
		m_cx = x;	m_cy = y;
	}
	int get_r(){return m_r;}
	int get_cx(){return m_cx;}
	int get_cy(){return m_cy;}
	
	void relation_cir_pos(Circle &c){
		int i = abs(m_cx - c.get_cx());
		int j = abs(m_cy - c.get_cy());
		int dis = sqrt(j*j + i*i);
		
		if(dis == m_r + c.get_r())	cout<<"两个圆相切"<<endl;
		else if(dis > m_r + c.get_r())	cout<<"两个圆相离"<<endl;
		else	cout<<"两个圆相交"<<endl;
		
		return;
	}	
private:
	int m_r;
	int m_cx;
	int m_cy;	
};
int main()
{
	Point p1, p2;
	p1.set_xy(1,1); p2.set_xy(4,5);
	p1.get_dist(p2);
	
	cout<<"----------------"<<endl;
	Circle c1, c2;
	
	c1.set_r();
	c1.set_cir_pos();
	
	c2.set_r();
	c2.set_cir_pos();
	
	c1.relation_cir_pos(c2);
	
	return 0;
}
#endif

#if 0
class Rectangle{
public:
	void set_l_xy(){
		cout<<"请输入左下角的坐标：";
		int x, y;
		cin>>x>>y;
		m_l_x = x;
		m_l_y = y;
	}
	void set_r_xy(){
		cout<<"请输右上角的坐标：";
		int x, y;
		cin>>x>>y;
		m_r_x = x;
		m_r_y = y;
	}
	
	int get_lx(){return m_l_x;}
	int get_ly(){return m_l_y;}
	int get_rx(){return m_r_x;}
	int get_ry(){return m_r_y;}
	
	void get_area(){
		cout<<"矩形的面积为："<<(m_r_y-m_l_y)*(m_r_x-m_l_x)<<endl;
		return;
	}
	
private:
	int m_l_x;
	int m_l_y;
	int m_r_x;
	int m_r_y;
};

int main()
{
	Rectangle r;
	r.set_l_xy();
	r.set_r_xy();
	r.get_area();
	return 0;
}
#endif

class Tree{
public:
	void set_ages(int age){m_ages = age;}
	int age(){return m_ages;}
	
	void grow(int years){m_ages += years;}
private:
	int m_ages;
}
