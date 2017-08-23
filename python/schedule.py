MAX_CURRENT_TIME = 100

class Schedule:
    schedule = {}
    current_time = 0

    def __len__(self):
        return len(self.schedule)

    def __repr__(self):
        return str(self.schedule)

    def register_event(self, creature=None, dtime=0):
        self.schedule[creature] = self.current_time + dtime

    def next_creature(self):
        creature, time = min(self.schedule.items(), key=lambda item:item[1])
        self.schedule.pop(creature)
        self.current_time = time
        return creature

    def remove(self, creature):
        print("Removing from schedule")
        print(self)
        self.schedule.pop(creature)
        print(self)
