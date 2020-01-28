% determine how hot it
isHot(HowHot, Temp) :-
	Temp >= 100,
	HowHot = 'very';
	Temp < 100,
	Temp >= 90,
	HowHot = 'pretty';
	Temp < 90,
	Temp >= 70,
	HowHot = 'perfect';
	Temp < 70,
	HowHot = 'cold'.
