class Event:
    def __init__(self, owner=owner, time=time):
        self.owner = owner
        Scheduler.register(self, time)

class Scheduler:
    schedule = {}

    @classmethod
    def register(cls, event, time):
        cls.schedule[event] = time

    @classmethod
    def next_event(cls):
        event, time = min(cls.schedule.items(), key=lambda item:item[1])
        cls.schedule.pop(event)
        self.current_time = time
        return event

    def run(self):
        self.initialize()  # Whatever it means

        while len(Scheduler.schedule) > 0 or current_time < MAX_CURRENT_TIME:
            current_event = self.next_event()
            current_event.owner.act()  # Prochaine action dans l'event ou dans la créature ?
