extern crate chrono;

use chrono::{NaiveDate, Duration, Datelike};

fn main() {
    // set start date
    let start: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
    // set end date
    let end: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);

    // array for counting the numerology numbers
    // note that index 0 stores the count for number 1 -> index 8 stores count for nr 9
    let numbers: [u64; 8] = [0; 8];

    calc_numerology_number(start);

    while date_is_less(start, end) {
        let start = start + Duration::days(1);
    }
}

fn date_is_less(d1: NaiveDate, d2: NaiveDate) -> bool {
    false
}

fn calc_numerology_number(d: NaiveDate) -> u8 {
    let mut yr = d.year();
    let mut mt = d.month();
    let mut dy = d.day();

    let mut number: u8 = 0;

    // concatenate numbers to string
    let concat_str: String = yr.to_string() + &mt.to_string() + &dy.to_string();
    let vec_nums: Vec<&str> = concat_str.split("").collect::<Vec<&str>>();
    //let vec_nums: Vec<u8> = vec_nums.parse::<u8>().collect().unwrap();
    //.parse::<u8>().unwrap();
    
    /*
    for _ in 0..2 {
        number += dy as u8 % 10;
        dy /= 10;
    }
    println!("{}", number);

    for _ in 0..2 {
        number += mt as u8 % 10;
        mt /= 10;
    }
    println!("{}", number);

    for _ in 0..4 {
        number += yr as u8 % 10;
        yr /= 10;
    }
    println!("{}", number);
    */

    // TODO: right now, I am too stupid to come up with a good algorithm,
    // and this below is not safe for bigger numbers
    // so please, when I have more brainpower, re-implement this

    let mut bufnum = number;
    number = 0;

    while bufnum > 9 {
        number += bufnum % 10;
        bufnum /= 10;
    }

    number
}

#[cfg(test)]
mod tests {
    use chrono::{NaiveDate, Duration, Datelike};
    #[test]
    fn calc_numerology_number_works_1() {
        let date: NaiveDate = NaiveDate::from_ymd(2000, 1, 1);
        assert_eq!(super::calc_numerology_number(date), 4);
    }

    #[test]
    fn calc_numerology_number_works_2() {
        let date: NaiveDate = NaiveDate::from_ymd(2002, 12, 14);
        assert_eq!(super::calc_numerology_number(date), 3);
    }
}
