
#include <iostream>
#include <memory>
// A notification system that sends alerts via different channels.

//// Step A – Write the BAD version first (to feel the pain)

// enum ChannelType
// {
// 	email,
// 	sms,
// 	push,
// slack
// };

// class Notifier
// {
// public:
// 	void send(ChannelType type)
// 	{
// 		switch (type)
// 		{
// 		case ChannelType::email:
// 			std::cout << "Sending email to user@example.com" << std::endl;
// 			break;

// 		case ChannelType::sms:
// 			std::cout << "Sending SMS to +123456789" << std::endl;
// 			break;

// 		case ChannelType::push:
// 			std::cout << "Sending push notification to device" << std::endl;
// 			break;

// 		default:
// 			break;
// 		}
// 	}
// };

// int main()
// {
// 	Notifier notify;
// 	notify.send(ChannelType::email);

// 	return 0;
// }

//// Step B – Refactor to GOOD version following the principles

class INotificationChannel
{
public:
	virtual void send(const std::string &msg) = 0;
	virtual ~INotificationChannel() = default;
};

class SlackChannel : public INotificationChannel
{
public:
	void send(const std::string &msg) override
	{
		std::cout << "Sending to Slack" << std::endl;
	}
};

class EmailChannel : public INotificationChannel
{
public:
	void send(const std::string &msg) override
	{
		std::cout << "Sending email to user@example.com" << std::endl;
	}
};

class SmsChannel : public INotificationChannel
{
public:
	void send(const std::string &msg) override
	{
		std::cout << "Sending sms to" << std::endl;
	}
};
class PushChannel : public INotificationChannel
{
public:
	void send(const std::string &msg) override
	{
		std::cout << "Sending by pushing" << std::endl;
	}
};

class Notifier
{
public:
	void send(INotificationChannel &channel, const std::string &msg)
	{
		channel.send(msg);
	}
};

int main()
{
	Notifier notify;

	PushChannel pushChannel;
	SmsChannel smsChannel;
	EmailChannel emailChaneel;

	notify.send(pushChannel, "");
	notify.send(emailChaneel, "");
	notify.send(smsChannel, "");

	return 0;
}