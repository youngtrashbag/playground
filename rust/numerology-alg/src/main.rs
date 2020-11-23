extern crate chrono;

use chrono::{NaiveDate, Duration, Datelike};

fn main() {
    // set start date
    let mut start: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
    // set end date
    let end: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);

    // array for counting the numerology numbers
    // note that index 0 stores the count for number 1 -> index 8 stores count for nr 9
    let numbers: [u64; 8] = [0; 8];

    while date_is_less(start, end) {
        println!("start: {:?}\nend: {:?}", start, end);
        start = start + Duration::days(1);
    }
}

/// true, if date 1 is less(or earlier) than date 2
fn date_is_less(d1: NaiveDate, d2: NaiveDate) -> bool {
    if d1.year() <= d2.year() {
        if d1.month() <= d2.month() && d1.year() <= d2.year() {
            if d1.day() <= d2.day() && (d1.month() <= d2.month() && d1.year() <= d2.year()) {
                return true;
            }
        }
    }

    false
}

fn calc_numberology_number(d: NaiveDate) -> u8 {
    let mut sum: u32 = 0;
    sum += d.year() as u32;
    sum *= 100;
    sum += d.month() as u32;
    sum *= 100;
    sum += d.day() as u32;
    println!("sum {}", sum);

    while sum > 9 {
        sum = calc_digit_sum(&sum).into();
    }

    sum as u8
}

fn calc_digit_sum(number: &u32) -> u8 {
    let mut number: u32 = *number;
    let mut sum: u8 = 0;

    while number > 0 {
        sum += (number % 10) as u8;
        number /= 10;
    }
    
    sum 
}

#[cfg(test)]
mod tests {
    use chrono::{NaiveDate, Datelike};
    #[test]
    fn calc_numerology_number_works_1() {
        let date: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        assert_eq!(super::calc_numberology_number(date), 4);
    }

    #[test]
    fn calc_numerology_number_works_2() {
        let date: NaiveDate = NaiveDate::from_ymd(2002, 12, 14);
        assert_eq!(super::calc_numberology_number(date), 3);
    }
}
