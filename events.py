import random

hasEvent = {}

def convertFormat(x, y):
	key = "{} {}".format(x, y)
	return key

def eventsGenerator():

	number = random.randint(5, 100)
	events = []

	for i in range(number):
		while True:
			x = random.randint(-10, 10)
			y = random.randint(-10, 10)
			key = convertFormat(x, y)

			if hasEvent.get(key, False):
				continue
			hasEvent[key] = True
	
			tickets = ticketsGenerator()
			events.append((x, y, tickets, (i + 1)))
			break

	return events

def ticketsGenerator():

	number = random.randint(0, 100)
	tickets = []

	for i in range((number + 1)):
		price = round(random.uniform(1, 100), 2)
		tickets.append((price, number))

	tickets = sorted(tickets, key=lambda x: int(x[0]))

	return tickets

def distance(c1, c2):
	x1, y1 = c1
	x2, y2 = c2

	return abs(x1 - x2) + abs(y1 - y2)

def findEvents(events, user):

	info = []

	for i in range(len(events)):
		eventID = events[i][3]
		dis = distance(user, events[i][:2])
		price = events[i][2][0][0]
		number = events[i][2][0][1]

		info.append((eventID, dis, price, number))

	info = sorted(info, key=lambda x: x[1])

	return info[:5]

def idGenerator(num):
	if num >= 10:
		return '0' + str(num)
	else:
		return '00' + str(num)

def main():

	events = eventsGenerator()

	while True:

		try:

			user = input("\nWhere are you? (Enter exit to exit) ")

		except:

			print("\nUnable to retrieve input, exiting the program")
			break

		if user == "exit":
			break

		if (not user.replace(",", "").replace(" ", "").replace("(", "").replace(")", "").replace("+", "").replace("-", "").isdigit()) or (len(user) < 2):
			print("Invalid Input. Coordinates must be digits within range -10 to 10\n")
			continue

		user = list(map(int, user.split(",")))

		if (user[0] > 10 or user[0] < -10) or (user[1] > 10 or user[1] < -10):
			print("Invalid Input. Coordinates must be digits within range -10 to 10\n")
			continue

		closest = findEvents(events, user)

		print("\nEvents closest to ({}, {}):\n".format(user[0], user[1]))

		for event in closest:
			eventID = idGenerator(event[0])
			print("Event Info: ID -> {}, Price -> ${}, {} tickets remaining, Distance -> {}".format(eventID, event[2], event[3], event[1]))

	print("Shutting Down...")

if __name__ == "__main__":
	main()