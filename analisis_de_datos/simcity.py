WIDTH, HEIGHT = 10, 10
city = [['.' for _ in range(WIDTH)] for _ in range(HEIGHT)]

BUILDING_COSTS = {
    'h': 1000,  # House
    's': 2000,  # Shop
    'f': 3000,  # Factory
    'r': 500    # Road
}

player_money = 15000

def print_city():
    print('\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n')
    print(f"Your current balance: ${player_money}")
    for row in city:
        print(' '.join(row))
    print()

def place_building(building):
    global player_money

    building = building.lower()  # Convert building to lowercase

    if player_money < BUILDING_COSTS[building]:
        print(f"Not enough money to place {building}. You need {BUILDING_COSTS[building] - player_money} more.")
        return

    while True:
        x = int(input(f"Enter X coordinate (0-{WIDTH-1}) for {building}: "))
        y = int(input(f"Enter Y coordinate (0-{HEIGHT-1}) for {building}: "))
        
        if 0 <= x < WIDTH and 0 <= y < HEIGHT and city[y][x] == '.':
            city[y][x] = building
            player_money -= BUILDING_COSTS[building]
            # Update the building case based on its adjacency to a road
            update_building_case(x, y)
            break
        else:
            print("Invalid location. Try again.")

def remove_building():
    global player_money

    x = int(input(f"Enter X coordinate (0-{WIDTH-1}) of the building to remove: "))
    y = int(input(f"Enter Y coordinate (0-{HEIGHT-1}) of the building to remove: "))

    building = city[y][x].lower()

    if building in BUILDING_COSTS:
        refund = BUILDING_COSTS[building] // 2
        player_money += refund
        city[y][x] = '.'

        # If we're removing a road
        if building == 'r':
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nx, ny = x + dx, y + dy

                # If we find an uppercase building
                if 0 <= nx < WIDTH and 0 <= ny < HEIGHT and city[ny][nx].isupper():

                    # Check if this building is still adjacent to a road
                    if not is_adjacent_to_road(nx, ny):
                        city[ny][nx] = city[ny][nx].lower()

        print(f"{building.upper()} removed. You got a refund of ${refund}.")
    else:
        print("There's no building at that location. Please try again.")



def update_building_case(x, y):
    # Check the surrounding cells (above, below, left, right)
    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        nx, ny = x + dx, y + dy
        if 0 <= nx < WIDTH and 0 <= ny < HEIGHT:
            # If the adjacent cell is a road and the current cell is a building, uppercase it
            if city[ny][nx] == 'r' and city[y][x] in ['h', 's', 'f']:
                city[y][x] = city[y][x].upper()
            # If the adjacent cell is a building and the current cell is a road, uppercase the building
            elif city[y][x] == 'r' and city[ny][nx] in ['h', 's', 'f']:
                city[ny][nx] = city[ny][nx].upper()

def is_adjacent_to_road(x, y):
    # Check the surrounding cells (above, below, left, right)
    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        nx, ny = x + dx, y + dy
        if 0 <= nx < WIDTH and 0 <= ny < HEIGHT:
            if city[ny][nx] == 'r':
                return True
    return False

def collect_rent():
    global player_money
    
    # Initialize the counts
    house_count = 0
    shop_count = 0
    factory_count = 0

    # Count the number of each building type adjacent to roads for each row
    for row in city:
        house_count += row.count('H')
        shop_count += row.count('S')
        factory_count += row.count('F')

    # Calculate the total rent
    total_rent = (house_count * BUILDING_COSTS['h'] * 0.10 +
                  shop_count * BUILDING_COSTS['s'] * 0.10 +
                  factory_count * BUILDING_COSTS['f'] * 0.10)
    
    player_money += total_rent
    print(f"Collected ${total_rent} in rent!")



def main():
    global player_money

    print_city()

    while True:
        print("Choose an action:")
        print("1. Place House (H) - $1000")
        print("2. Place Shop (S) - $2000")
        print("3. Place Factory (F) - $3000")
        print("4. Place Road (R) - $500")
        print("5. Remove Building")
        print("6. Skip Turn")
        print("9. Quit")
        choice = input("> ")

        if choice in ['1', '2', '3', '4']:
            building = ['h', 's', 'f', 'r'][int(choice) - 1]  # Ensure lowercase
            place_building(building)
        elif choice == '5':
            remove_building()
        elif choice == '6':
            print('Skipping turn...')
        elif choice == '9':
            print("Thanks for playing!")
            break
        else:
            print("Invalid choice. Try again.")
        
        print_city()
        collect_rent()  # Add this line to collect rent at the start of each iteration


if __name__ == "__main__":
    main()
