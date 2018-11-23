peoples = ["Steve Jobs", "Bill Gates", "Warren Buffett"]
for people in peoples:
    print(people + ", I want to invite you to dinner together.")

print("\nI found a bigger dining table.\n")

peoples.insert(0, "Jack Ma")
peoples.insert(2, "Lawrence Edward Page")
peoples.append("Sergey Brin")

for people in peoples:
    print(people + ", I want to invite you to dinner together.")

print("\nThe table cannot be delivered on time, so only two guests can be invited.\n")

while len(peoples) > 2:
    remove_guest = peoples.pop()
    print("Sorry, " + remove_guest + ", see you next time.")

print("\n")

for people in peoples:
    print(people + ", see you tonight !")

del peoples[1]
del peoples[0]
print(peoples)
