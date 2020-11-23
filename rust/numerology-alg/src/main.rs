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
    use chrono::{NaiveDate};
    #[test]
    fn calc_numerology_number_works_1() {
        let date: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        assert_eq!(super::calc_numberology_number(date), 4);
    }

    #[test]
    fn calc_numerology_number_works_2() {
        let date: NaiveDate = NaiveDate::from_ymd(2020, 7, 4);
        assert_eq!(super::calc_numberology_number(date), 7);
    }

    #[test]
    /// date is less
    fn compare_date_1() {
        let d1: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        let d2: NaiveDate = NaiveDate::from_ymd(2000, 1, 2);
        assert_eq!(super::date_is_less(d1, d2), true);
    }

    #[test]
    /// date is more
    fn compare_date_1_1() {
        let d1: NaiveDate = NaiveDate::from_ymd(2000, 1, 2);
        let d2: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        assert_eq!(super::date_is_less(d1, d2), false);
    }

    #[test]
    /// date is more (two days)
    fn compare_date_1_2() {
        let d1: NaiveDate = NaiveDate::from_ymd(2000, 1, 3);
        let d2: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        assert_eq!(super::date_is_less(d1, d2), false);
    }

    #[test]
    /// date is the same
    fn compare_date_2() {
        let d1: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        let d2: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        assert_eq!(super::date_is_less(d1, d2), false);
    }

    #[test]
    /// one day more
    fn compare_date_3() {
        let d1: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        let d2: NaiveDate = NaiveDate::from_ymd(2000, 1, 2);
        assert_eq!(super::date_is_less(d1, d2), true);
    }

    #[test]
    /// two days more
    fn compare_date_3_1() {
        let d1: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        let d2: NaiveDate = NaiveDate::from_ymd(2000, 1, 3);
        assert_eq!(super::date_is_less(d1, d2), true);
    }

    #[test]
    /// one month more
    fn compare_date_4() {
        let d1: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        let d2: NaiveDate = NaiveDate::from_ymd(2000, 2, 1);
        assert_eq!(super::date_is_less(d1, d2), true);
    }

    #[test]
    /// two months more
    fn compare_date_4_1() {
        let d1: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        let d2: NaiveDate = NaiveDate::from_ymd(2000, 3, 1);
        assert_eq!(super::date_is_less(d1, d2), true);
    }

    #[test]
    /// one year more
    fn compare_date_5() {
        let d1: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        let d2: NaiveDate = NaiveDate::from_ymd(2001, 1, 1);
        assert_eq!(super::date_is_less(d1, d2), true);
    }

    #[test]
    /// two years more
    fn compare_date_5_1() {
        let d1: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        let d2: NaiveDate = NaiveDate::from_ymd(2002, 1, 1);
        assert_eq!(super::date_is_less(d1, d2), true);
    }
}
