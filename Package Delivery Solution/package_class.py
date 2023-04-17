# package class creation
class packages:
    def __init__(self, id, address, city, state, zip_code, dead_line, size, stats) -> object:
        self.id = id
        self.address = address
        self.city = city
        self.state = state
        self.zip_code = zip_code
        self.dead_line = dead_line
        self.size = size
        self.stats = stats
        self.departure_time = None
        self.delivery_time = None

    def __str__(self):
        return f"{self.id}, {self.address}, {self.city}, {self.state}, {self.zip_code}, {self.dead_line}, {self.size}, {self.delivery_time}, {self.stats}"

    # delivered , en route or at the hub logic
    def updates(self, time_change):
        if self.delivery_time < time_change:
            self.stats = "delivered"
        elif self.departure_time > time_change:
            self.stats = "en route"
        else:
            self.stats = "at the hub"