BUILDING_COSTS = {
    'l': 1000,  # House
    'm': 2000,  # Shop
    'h': 3000,  # Factory
    'r': 500    # Road
}

class Building:
    def __init__(self, kind):
        self.kind = kind.lower()
        self.cost = BUILDING_COSTS[self.kind]
        self.is_active = False  # Active when next to a road

    def activate(self):
        self.is_active = True

    def deactivate(self):
        self.is_active = False

class City:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.grid = [['.' for _ in range(width)] for _ in range(height)]

    def print_city(self, player_money):
        print(f"Your current balance: ${player_money}")
        for row in self.grid:
            print(' '.join(row))
        print()

    def place_building(self, x, y, building):
        self.grid[y][x] = building.kind.upper() if building.is_active else building.kind

    def remove_building(self, x, y):
        self.grid[y][x] = '.'

    def update_building_cases(self):
        for y in range(self.height):
            for x in range(self.width):
                building = self.grid[y][x].lower()
                if building in BUILDING_COSTS:
                    if self.is_adjacent_to_road(x, y):
                        self.grid[y][x] = building.upper()
                    else:
                        self.grid[y][x] = building.lower()

    def is_adjacent_to_road(self, x, y):
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < self.width and 0 <= ny < self.height:
                if self.grid[ny][nx].lower() == 'r':
                    return True
        return False

class Player:
    def __init__(self, starting_money):
        self.money = starting_money

    def can_afford(self, building):
        return self.money >= building.cost

    def make_payment(self, amount):
        self.money -= amount

    def receive_money(self, amount):
        self.money += amount

    def collect_rent(self, city):
        rent = sum(city.grid[y].count(building.upper()) * (BUILDING_COSTS[building.lower()] * 0.10) for y in range(city.height) for building in ['l', 'm', 'h'])
        self.receive_money(rent)
        print(f"Collected ${rent} in rent!")

class Game:
    def __init__(self, width, height, starting_money):
        self.city = City(width, height)
        self.player = Player(starting_money)

    def main_loop(self):
        while True:
            self.city.print_city(self.player.money)
            print("Choose an action:")
            print("1. Place Low Urban Zone (L) - $1000")
            print("2. Place Medium Urban Zone (M) - $2000")
            print("3. Place High Urban Zone (H) - $3000")
            print("4. Place Road (R) - $500")
            print("5. Remove Something")
            print("6. Skip Turn")
            print("9. Quit")
            choice = input("> ")

            if choice in ['1', '2', '3', '4']:
                building_kind = ['l', 'm', 'h', 'r'][int(choice) - 1]
                building = Building(building_kind)
                if self.player.can_afford(building):
                    x = int(input(f"Enter X coordinate (0-{self.city.width-1}) for {building.kind}: "))
                    y = int(input(f"Enter Y coordinate (0-{self.city.height-1}) for {building.kind}: "))
                    if 0 <= x < self.city.width and 0 <= y < self.city.height and self.city.grid[y][x] == '.':
                        self.city.place_building(x, y, building)
                        self.player.make_payment(building.cost)
                        self.city.update_building_cases()
                    else:
                        print("Invalid location. Try again.")
                else:
                    print(f"Not enough money to place {building.kind}. You need ${building.cost - self.player.money} more.")
            elif choice == '5':
                x = int(input(f"Enter X coordinate (0-{self.city.width-1}) of the building to remove: "))
                y = int(input(f"Enter Y coordinate (0-{self.city.height-1}) of the building to remove: "))
                if self.city.grid[y][x].lower() in BUILDING_COSTS:
                    building_kind = self.city.grid[y][x].lower()
                    refund = BUILDING_COSTS[building_kind] // 2
                    self.city.remove_building(x, y)
                    self.player.receive_money(refund)
                    self.city.update_building_cases()
                    print(f"{building_kind.upper()} removed. You got a refund of ${refund}.")
                else:
                    print("There's no building at that location. Please try again.")
            elif choice == '6':
                print('Skipping turn...')
            elif choice == '9':
                print("Thanks for playing!")
                break
            else:
                print("Invalid choice. Try again.")

            self.player.collect_rent(self.city)

if __name__ == "__main__":
    game = Game(10, 10, 15000)
    game.main_loop()
