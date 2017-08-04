import time
import threading


rang = 0
mage = 1

class Player:
	def __init__(self):
		self.pray = None
		self.health = 10000
	
	def get_hit(damage, type_d):
		sleep(.5)
		if type_d == self.pray:
			self.health -= damage/2
			print(self.health)
			return 1
		else:
			self.health -= damage
			return 0
	
	def heal(amt):
		self.health+=amt
	
	def switch_prayer(style):
		self.pray = style
	def main_loop():
		while True:
			a = input()
			if a == 's':
				self.pray = rang
			if a == 'd':
				self.pray = mage
def Rax:
	def __init__(self, player):
		self.style = mage
		self.health = 100000
		self.fighting = player
	def hit(player, damage):
		if self.style = rang:
			print("Range attack incoming")
		else:
			print("Mage attack incoming")
		time.sleep(2.5)
		player.get_hit(damage, self.style)
	def main_loop():
		while True:
			self.hit(player,1000)
				
