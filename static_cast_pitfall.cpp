#include <iostream>
using namespace std;

class Window {
public:
	virtual void onResize()
	{cout<<"resize window";}
};

class specialWindow:public Window {
public:
	virtual void onResize() {
		static_cast<Window>(*this).onResize(); //Just use Window::onResize() instead
	}
};

int main() {
	Window* w;
	specialWindow* s;

	//w->onResize();
	//s->onResize();

	return 0;
}
