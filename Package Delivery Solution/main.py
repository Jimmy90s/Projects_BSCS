# Name : James Laurie
# Student id: 010769546

import truck_class
from hash_table_class import hash_table
from package_class import packages

import csv
import datetime


# distances file loader
with open("data_folder/distances.csv") as file:
    distance_file = csv.reader(file)
    distance_file = list(distance_file)

# addresses file loader
with open("data_folder/addresses.csv") as file_1:
    address_file = csv.reader(file_1)
    address_file = list(address_file)

# packages file loader
with open("data_folder/packages.csv") as file_2:
    package_file = csv.reader(file_2)
    package_file = list(package_file)


# Create package objects from the data_folder package file
# Load package objects into the hash table: packages_table
def load(file, package_hash_table):
    with open(file) as package_info:
        package_data = csv.reader(package_info)
        for p in package_data:
            p_id = int(p[0])
            p_address = p[1]
            p_city = p[2]
            p_state = p[3]
            p_zipcode = p[4]
            p_deadline_time = p[5]
            p_weight = p[6]
            p_status = "At Hub"

            # packages object
            p = packages(p_id, p_address, p_city, p_state, p_zipcode, p_deadline_time, p_weight, p_status)

            # Insert data into hash table
            package_hash_table.add_item(p_id, p)


# Method for finding distance between two addresses
def distance(x, y):
    dist = distance_file[x][y]
    if not dist != '':
        dist = distance_file[y][x]
    return float(dist)


# Method to get address number from string literal of address
def get_address(address):
    for r in address_file:
        if address in r[2]:
            return int(r[0])


# Create load object first_truck
first_truck = truck_class.trucks(16, 18, None, [1, 13, 14, 15, 16, 20, 29, 30, 31, 34, 37, 40], 0.0, "4001 South 700 East", datetime.timedelta(hours=8))

# Create load object second_truck
second_truck = truck_class.trucks(16, 18, None, [3, 6, 12, 17, 18, 19, 21, 22, 23, 24, 26, 27, 35, 36, 38, 39], 0.0, "4001 South 700 East", datetime.timedelta(hours=10, minutes=20))

# Create load object third_truck
third_truck = truck_class.trucks(16, 18, None, [2, 4, 5, 6, 7, 8, 9, 10, 11, 25, 28, 32, 33], 0.0, "4001 South 700 East", datetime.timedelta(hours=9, minutes=5))

# Create hash table
packages_table = hash_table()

# Load package into hash table
load("data_folder/packages.csv", packages_table)


# Procedure for using the nearest neighbor algorithm to order packages on a particular load
# Once the packages are sorted, this technique also determines the distance that a specific load travels.
def nearest_neighbor_delivery(load):
    # Place all package into array of still_needed
    still_needed = []
    for package_id in load.package:
        pack = packages_table.lookup_id(package_id)
        still_needed.append(pack)
    # To enable the package to be reinserted into the load in the order # of the closest neighbor, clear the package list for the specified load.
    load.package.clear()

    # Continue going through the inventory of still-needed until none are left.
    #  the closest package is added
    while not len(still_needed) <= 0:
        next_local = 2000
        next_load = None
        for pack in still_needed:
            if distance(get_address(load.address), get_address(pack.address)) > next_local:
                continue
            next_local = distance(get_address(load.address), get_address(pack.address))
            next_load = pack
        # the package list's next nearest package is added
        load.package.append(next_load.id)
        # the same load gets taken from the still_needed list.
        still_needed.remove(next_load)
        load.mile += next_local
        # changes the load's current address to the package it traveled to.
        load.address = next_load.address
        # Updates the distance traveled by the load to reach the closest package.
        load.time += datetime.timedelta(hours=next_local / 18)
        next_load.delivery_time = load.time
        next_load.departure_time = load.depart


# Begin loading trucks
nearest_neighbor_delivery(first_truck)
nearest_neighbor_delivery(second_truck)

# wait to make sure that load 3 won't depart until one of the first two vehicles has
# completed delivering.
t = min(first_truck.time, second_truck.time)
third_truck.depart = t
nearest_neighbor_delivery(third_truck)


class Main:
    # Interface
    print('WGUPS ROUTING PROGRAM')
    print('Total Miles for all trucks:', (first_truck.mile + second_truck.mile + third_truck.mile))# Print total mile for all trucks
    # start screen will ask user to type 'start' to begin
    text = input("Please type 'start' to begin.")
    if not text != 'start':
        try:
            # Will be asked for a time to start
            user_time = input("Please enter a time to check stats of package(s). Use the following format, HH:MM")
            (h, m) = user_time.split(":")
            time_change = datetime.timedelta(hours=int(h), minutes=int(m))
            # Will be asked if you would like to see a single package or all
            second_input = input("To view the stats of an individual package type 'single'. For a all packages type 'all'.")
            # will ask for an id if user types 'single'
            if not second_input != "single":
                try:
                    # display single package by id
                    solo_input = input("Enter the numeric package id")
                    package = packages_table.lookup_id(int(solo_input))
                    package.updates(time_change)
                    print(str(package))
                except ValueError:
                    print('Entry invalid. Closing program.')
                    exit()
            # display all package info at once if user types 'all'
            elif not second_input != 'all':
                try:
                    for id in range(1, 41):
                        package = packages_table.lookup_id(id)
                        package.updates(time_change)
                        print(str(package))
                except ValueError:
                    print('Invalid Entry. Closing.')
                    exit()
            else:
                exit()
        except ValueError:
            print('Invalid Entry. Closing.')
            exit()
    elif 'start' != input:
        print('Entry invalid. Closing.')
        exit()