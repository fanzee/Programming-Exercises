peoples = ["Steve Jobs", "Bill Gates", "Warren Buffett"]
for people in peoples:
    print(people + ", I want to invite you to dinner together.")

print("\nI found a bigger dining table.\n")

peoples.insert(0, "Jack Ma")
peoples.insert(2, "Lawrence Edward Page")
peoples.append("Sergey Brin")

for people in peoples:
    print(people + ", I want to invite you to dinner together.")
