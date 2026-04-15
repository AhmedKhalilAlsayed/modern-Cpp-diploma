#include <iostream>
#include <memory>

// button interface
class IButton
{
public:
	virtual void draw() = 0;
	virtual ~IButton() = default;
};

// concretes

class ClassicButton : public IButton
{
	void draw() override
	{
		std::cout << "Classic button" << std::endl;
	}
};
class ModernButton : public IButton
{
	void draw() override
	{
		std::cout << "Modern button" << std::endl;
	}
};
// class ButtonFactory
// {
// public:
// 	static std::unique_ptr<IButton> createClassic()
// 	{
// 		return std::make_unique<ClassicButton>();
// 	}
// 	static std::unique_ptr<IButton> createModern()
// 	{
// 		return std::make_unique<ModernButton>();
// 	}
// };

// textBox interface
class ITextBox
{
public:
	virtual void show() = 0;
	virtual ~ITextBox() = default;
};

// concretes

class ClassicTextBox : public ITextBox
{
	void show() override
	{
		std::cout << "Classic TextBox" << std::endl;
	}
};
class ModernTextBox : public ITextBox
{
	void show() override
	{
		std::cout << "Modern TextBox" << std::endl;
	}
};

// class TextBoxFactory
// {
// public:
// 	static std::unique_ptr<ITextBox> createClassic()
// 	{
// 		return std::make_unique<ClassicTextBox>();
// 	}
// 	static std::unique_ptr<ITextBox> createModern()
// 	{
// 		return std::make_unique<ModernTextBox>();
// 	}
// };

// window interface
class IWindow
{
public:
	virtual void drawScreen() = 0;
	virtual ~IWindow() = default;
};

// concretes
class ClassicWindow : public IWindow
{
public:
	void drawScreen() override
	{
		std::cout << "Classic Window" << std::endl;
	}
};
class ModernWindow : public IWindow
{
public:
	void drawScreen() override
	{
		std::cout << "Modern Window" << std::endl;
	}
};

// widgets
class IWidgetFactory
{
public:
	virtual std::unique_ptr<IButton> createButton() = 0;
	virtual std::unique_ptr<ITextBox> createTextBox() = 0;
	virtual std::unique_ptr<IWindow> createWindow() = 0;
	virtual ~IWidgetFactory() = default;
};

class ClassicWidgetFactory : public IWidgetFactory
{
public:
	std::unique_ptr<IButton> createButton() override
	{
		return std::make_unique<ClassicButton>();
	}
	std::unique_ptr<ITextBox> createTextBox() override
	{
		return std::make_unique<ClassicTextBox>();
	}
	std::unique_ptr<IWindow> createWindow() override
	{
		return std::make_unique<ClassicWindow>();
	}
};

class ModernWidgetFactory : public IWidgetFactory
{
public:
	std::unique_ptr<IButton> createButton() override
	{
		return std::make_unique<ModernButton>();
	}
	std::unique_ptr<ITextBox> createTextBox() override
	{
		return std::make_unique<ModernTextBox>();
	}

	std::unique_ptr<IWindow> createWindow() override
	{
		return std::make_unique<ModernWindow>();
	}
};