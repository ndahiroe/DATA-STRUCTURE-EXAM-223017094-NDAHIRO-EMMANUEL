
from collections import deque

class AuctionDeque:
    def __init__(self):
        self.deque = deque()

    def add_bid(self, bid):
        self.deque.append(bid)

    def process_bid(self):
        if self.deque:
            return self.deque.popleft()
        return None

    def display(self):
        print("Auction Bids:", list(self.deque))

# Example usage
if __name__ == "__main__":
    auction_deque = AuctionDeque()
    auction_deque.add_bid(300)
    auction_deque.add_bid(450)
    auction_deque.display()
    print("Processing bid:", auction_deque.process_bid())
