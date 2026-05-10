#include <string>
#include <vector>
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
	virtual std::string getChannelName() = 0;
	virtual ~INotificationChannel() = default;
};

class SlackChannel : public INotificationChannel
{
public:
	void send(const std::string &msg) override
	{
		std::cout << "Sending to Slack: " << msg << std::endl;
	}
	std::string getChannelName() override
	{
		return "slack";
	}
};

class EmailChannel : public INotificationChannel
{
public:
	void send(const std::string &msg) override
	{
		std::cout << "Sending email to user@example.com: " << msg << std::endl;
	}
	std::string getChannelName() override
	{
		return "email";
	}
};

class SmsChannel : public INotificationChannel
{
public:
	void send(const std::string &msg) override
	{
		std::cout << "Sending sms: " << msg << std::endl;
	}
	std::string getChannelName() override
	{
		return "sms";
	}
};
class PushChannel : public INotificationChannel
{
public:
	void send(const std::string &msg) override
	{
		std::cout << "Sending by pushing: " << msg << std::endl;
	}
	std::string getChannelName() override
	{
		return "push";
	}
};

class Notifier
{
	std::vector<std::unique_ptr<INotificationChannel>> vecChannels;

public:
	void sendByChannel(std::unique_ptr<INotificationChannel> channel, const std::string &msg)
	{
		channel->send(msg);
	}

	void addChannel(std::unique_ptr<INotificationChannel> channel)
	{
		std::unique_ptr<INotificationChannel> _channel = std::move(channel);

		// check of the channel is already exists, skip it

		for (const auto &e : vecChannels)
		{
			if (e->getChannelName() == _channel->getChannelName())
			{
				return;
				// break;
			}
		}

		vecChannels.push_back(std::move(_channel));
	}

	void removeChannel(const std::string &channelName)
	{

		for (auto it = vecChannels.begin(); it != vecChannels.end(); it++)
		{
			if ((*it)->getChannelName() == channelName)
			{
				vecChannels.erase(it);
				return;
			}
		}
	}

	void sendBroadcast(const std::string &msg) const
	{
		for (const auto &e : vecChannels)
		{
			e->send(msg);
		}

		// for (size_t i = 0; i < vecChannels.size(); i++)
		// {
		// 	vecChannels[i]->send(msg);
		// }

		// for (auto it = vecChannels.begin(); it != vecChannels.end(); it++)
		// {
		// 	(*it)->send(msg);
		// }
	}
};

int main()
{
	Notifier notify;

	notify.addChannel(std::make_unique<SmsChannel>());
	notify.addChannel(std::make_unique<SmsChannel>());
	notify.addChannel(std::make_unique<PushChannel>());

	notify.removeChannel(SmsChannel().getChannelName());

	notify.sendBroadcast("Hello system!");

	return 0;
}