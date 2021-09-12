class Power {
public:
	Power(double x = 2, double pow = 3) : base(x), power(pow) {}
	
	void set(double x, double pow) {
		base = x;
		power = pow;
	}
	
	/* 	расчет для вещественных чисел производится в несколько этапов:
		1. Сначала определяем, в какую степень возводим, в отрицательную или нет.
			Если база меньше 1 - меняем знак изначально переданной степени и пересчитываем базу;			
			Если в итоге получилась отрицательная степень - переворачиваем дробь, иначе считаем как есть;
		2. Считаем ln(base);
		3. Определяем итоговую степень, в которую будем возводить exp;
		4. Возводим e ^ power;
		5. Возвращаем result или 1 / result, если степень была отрицательная.		
	*/
	double calculate() {
		if(base < 0) return -1;
		if(base == 0) return 0;
		if(power - (int) power == 0) {
			double result = 1;
			for(int i = 0; i < power; i++)
				result *= base;
			return result;
		}
		
		if(base < 1) {
			base = 1 / base;
			power = -power;
		}
		
		if(power > 0) {
			countPowerMod();
			return getExpPowX();
		} else {
			power = -power;
			countPowerMod();
			return 1 / getExpPowX();
		}
	}
	
	
private:
	double base;
	double power;
	double powerMod;

	// считаем приблизительную площадь под кривой 1/x
	void countPowerMod() {
		const int STEPS_COUNT = 1000000;
		double sum = 0;
		
		double step = (base - 1) / STEPS_COUNT;
		double x = 1;
		for(int i = 0; i < STEPS_COUNT; i++) {
			sum += 1 / x * step;
			x += step;
		}

		powerMod = power * sum;
	}
	
	// раскладываем в ряд Тэйлора e ^ x
	double getExpPowX() {		
		return 1 + getTailorRowSum(1);
	}
	
	// в качестве х используем power * ln(base)
	double getTailorRowSum(double termNumber) {
		double divident = 1;
		double divider = 1;
		for(int i = 0; i < termNumber; i++) {
			divident *= powerMod;
			divider *= i + 1;
		}

		if(divident / divider < 0.0001) return 0;
		else return divident / divider + getTailorRowSum(termNumber + 1);
	}
};