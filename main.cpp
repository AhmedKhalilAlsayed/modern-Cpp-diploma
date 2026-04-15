#include <stdint.h>
#include "singleton_parking.cpp"
#include "factory.cpp"

int main()
{
	// std::unique_ptr<IButton> button = ButtonFactory::createModern();
	// button.get()->draw();

	std::unique_ptr<IWidgetFactory> widgetFactory;
	widgetFactory = std::make_unique<ModernWidgetFactory>();

	std::unique_ptr<IButton> button = widgetFactory.get()->createButton();
	std::unique_ptr<ITextBox> textbox = widgetFactory.get()->createTextBox();
	std::unique_ptr<IWindow> window = widgetFactory.get()->createWindow();
	button.get()->draw();
	textbox.get()->show();
	window.get()->drawScreen();

	return 0;
}