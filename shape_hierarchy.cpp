#include <iostream>
using namespace std;

class Shapes {              //Abstract base class
public:
	virtual void draw() = 0;//Pure virtual function

};
void Shapes::draw(){cout<<"Shape : init brush\n";}

class Polygon : public Shapes {       //Concrete class
public:
	void draw() {Shapes::draw();cout<<"Polygon: draw by triangulation\n";}
};

class ClosedConics: public Shapes {        //Abstract base class
    //pure virtual function is inherited
};

class Rectangle : public Polygon {         //Concrete class
	void draw() {Shapes::draw();cout<<"Rectangle: draw by lines\n";}
};

class Triangle : public Polygon {            //Concrete class
	void draw() {Shapes::draw();cout<<"Triangle: draw by lines\n";}
};

class Circle : public ClosedConics {      //Concrete class
	void draw() {Shapes::draw();cout<<"Circle: draw by Breshenham algorithm\n";}
};

class Ellipse : public ClosedConics {       //Concrete class
	void draw() {Shapes::draw();cout<<"Ellipse: draw by ... algorithm\n";}
};

int main()
{
	Shapes* arr[] = {new Rectangle,new Triangle, new Circle, new Ellipse};

	for (int i = 0; i<sizeof(arr)/sizeof(Shapes*) ; i++)
		arr[i]->draw();

	return 0;
}
