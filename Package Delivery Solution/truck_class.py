# load class creation
class trucks:
    def __init__(self, cap, move, load, package, mile, address, depart) -> object:
        self.cap = cap
        self.move = move
        self.load = load
        self.package = package
        self.mile = mile
        self.address = address
        self.depart = depart
        self.time = depart

    def __str__(self):
        return f"{self.cap}, {self.move}, {self.load}, {self.package}, {self.mile}, {self.address}, {self.depart}"
