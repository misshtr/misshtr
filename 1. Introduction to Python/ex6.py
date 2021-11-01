# function from http://stackoverflow.com/a/328122
def isBetween(a, b, c):
	crossproduct = (c[1] - a[1]) * (b[0] - a[0]) - (c[0] - a[0]) * (b[1] - a[1])
	if abs(crossproduct) != 0  : return False

	dotproduct = (c[0] - a[0]) * (b[0] - a[0]) + (c[1] - a[1])*(b[1] - a[1])
	if dotproduct < 0 : return False

	squaredlengthba = (b[0] - a[0])*(b[0] - a[0]) + (b[1] - a[1])*(b[1] - a[1])
	if dotproduct > squaredlengthba: return False
	return True

class HouseLocation:
	def __init__(self, street_name, x, y):      #DEFINING AN ADRESS
		# enter 1a. here
		if x not in range(0, 39):
			raise ValueError('x is not in range 0-40')
		if y not in range(0, 39):
			raise ValueError('y not in range 0-40')
		self.street_name = street_name
		self.x = x
		self.y = y

	def print_address(self):
		# enter 1b. here
		print(self.street_name + ':' + str(self.x) + ',' + str(self.y))

class Street:
	def __init__(self, street_name, map_symbol, street_ends):   #DEFINING A STREET
		self.house_locations = {}
		# enter 2a. here
		x1 = street_ends[0][0]
		x2 = street_ends[1][0]
		y1 = street_ends[0][1]
		y2 = street_ends[1][1]
		if len(map_symbol)!=1 or map_symbol.islower() is False: #demanding-single character and lowercase
			raise ValueError('map symbol is not lower case')
		if (x1 or x2 or y1 or y2) not in range(0, 40):
			raise ValueError('street ends are not in range 0-40')
		if (x1 == x2) and (y1 == y2):
			raise ValueError('street ends must have different values')
		self.street_name = street_name
		self.map_symbol = map_symbol
		self.street_ends = street_ends

	def valid_house_to_add(self, house): #I've got (x, y, street_name)
		# enter 2b. here
		end1 = self.street_ends[0]
		end2= self.street_ends[1]

		if (house.x, house.y) not in self.house_locations:
			return isBetween(end1, end2, (house.x, house.y))
		else:
			return False

	def add_house(self, house):
		# enter 2c. here
		if self.valid_house_to_add(house) == True:
			self.house_locations[(house.x),(house.y)] = True
		else:
			raise ValueError('house is not in range or already exists in house location')


class City:
	def __init__(self, city_name):
		self.streets = []
		# enter 3a. here
		self.city_name = city_name

	def valid_street_to_add(self, test_street):
		# enter 3b. here
		for i in range (len(self.streets)): #iterates over streets list to check if value exists
			st=self.streets[i]
			if st.street_name == test_street.street_name or st.map_symbol == test_street.map_symbol:
				return False
		return True

	def add_street(self, street):
		# enter 3c. here
		if self.valid_street_to_add(street) == True:
			self.streets.append(street)
		else:
			raise ValueError('street name or map symbol already exists in streets list')

	def print_map(self):
		# enter 3d. here
		self.streets.sort(key=lambda x: x.map_symbol)
		for i in range(40):
			for j in range(40):
				flag = 0
				for street in self.streets:
					if (i,j) in street.house_locations:
						if flag <= 0:
							flag += 1
							print(street.map_symbol, end='')
				if flag == 0:
					print('_', end='')
			print('\n')



### test 1
my_house = HouseLocation("mockingbird lane", 23, 36)
my_house.print_address()
### test 2
mockingbird = Street("mockingbird lane", "m", ((5, 36), (30, 36)))
frat_house = HouseLocation("mockingbird lane", 11, 36)
bad_house = HouseLocation("mockingbird lane", 31, 36)
mockingbird.add_house(my_house)

print(mockingbird.valid_house_to_add(frat_house))

mockingbird.add_house(frat_house)
print(mockingbird.valid_house_to_add(frat_house))  # house already present
print(mockingbird.valid_house_to_add(bad_house))  # bad coordinates
try:
	mockingbird.add_house(bad_house)  # ValueError
except ValueError as err:
	print("value err caught: ", err)

## test 3
Gotham = City("Gotham City")
bat_house = HouseLocation("batman lane", 11, 24)
joker_house = HouseLocation("batman lane", 11, 28)
catwoman_house = HouseLocation("batman lane", 11, 36)

bat_street = Street("batman lane", "b", ((11, 20), (11, 36)))
bat_street.add_house(bat_house)
bat_street.add_house(joker_house)
bat_street.add_house(catwoman_house)

print(Gotham.valid_street_to_add(mockingbird))  # True

Gotham.add_street(mockingbird)

print(Gotham.valid_street_to_add(bat_street))  # True
Gotham.add_street(bat_street)

print(Gotham.valid_street_to_add(bat_street))  # False

try:
	Gotham.add_street(bat_street)  # ValueError
except ValueError as err:
	print("value err caught: ", err)
print('\n\n')
Gotham.print_map()
