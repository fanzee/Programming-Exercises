peoples = ["Steve Jobs", "Bill Gates", "Warren Buffett"]
for people in peoples:
    print(people + ", I want to invite you to dinner together.")

print("\nFor some reasons, Steve Jobs can't come here tonight.\n")

peoples.remove("Steve Jobs")

peoples.insert(0, "Jack Ma")
for people in peoples:
    print(people + ", I want to invite you to dinner together.")
