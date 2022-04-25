Create TABLE Book(
	BookID varchar(20) PRIMARY KEY,
	Classification varchar(40),
	BookName varchar(40),
	Press varchar(40),
	PublicTime int(8),
	Author varchar(40),
	Price real,
	NumberAll int(5),
	StoreNumber int(5)
);
 
Create TABLE Card(
	CardID varchar(12) PRIMARY KEY,
	UserName varchar(20),
	Department varchar(20),
	Category bit
);
 
Create TABLE Admin(
	AdminID varchar(12) PRIMARY KEY,
	Password varchar(16),
	AdminName varchar(20),
	Contect varchar(11)
);
 
Create TABLE Record(
	BookID varchar(20),
	OutTime date,
	InTime date,
	AdminID varchar(12),
	CardID varchar(12),
	PRIMARY KEY (CardID, BookID),
	FOREIGN KEY (CardID) REFERENCES Card(CardID),
	FOREIGN KEY (BookID) REFERENCES Book(BookID)
);

alter table Book
add constraint check_stock check(storenumber>=0);
