class Scheduler:
    schedule = {}
    time = 0

    @classmethod
    def register_event(cls, creature=None, dtime=0):
        cls.schedule[creature] = cls.current_time + dtime

    @classmethod
    def next_creature(cls):
        creature, time = min(cls.schedule.items(), key=lambda item:item[1])
        cls.schedule.pop(creature)
        cls.current_time = time
        return creature

    def run(self):
        while len(Scheduler.schedule) > 0 or current_time < MAX_CURRENT_TIME:
            current_creature = self.next_creature()
            current_creature.act()  # Prochaine action dans l'event ou dans la créature ?
