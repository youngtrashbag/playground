use rand::{thread_rng, Rng};

const RANGE_LOW: u32 = 0;
const RANGE_HIGH: u32 = 100;

fn main() {
    let mut rng = thread_rng();
    let random_num: u32 = rng.gen_range(RANGE_LOW, RANGE_HIGH);

    let mut guessed_num: u32 = mid_of_range(RANGE_LOW, RANGE_HIGH);
    let mut lower_range: u32 = RANGE_LOW;
    let mut upper_range: u32 = RANGE_HIGH;

    let mut tries: u8 = 0;

    while guessed_num != random_num {
        if random_num > guessed_num {
            lower_range = guessed_num;
        } else if random_num < guessed_num {
            upper_range = guessed_num;
        }

        guessed_num = mid_of_range(lower_range, upper_range);

        println!("u{}\nl{}\ng{}", lower_range, upper_range, guessed_num);

        //incrementing tries it took
        //tries += 1;
    }

    //println!("random number has been guessed. it was {}\nit took {} tries.", random_num, tries);
    println!("random number has been guessed. it was {}\nit took {} tries.", random_num, tries);

    println!("0/100:{}", mid_of_range(0, 100));
    println!("1/100: {}", mid_of_range(1, 100));
    println!("0/21: {}", mid_of_range(0, 21));
    println!("1/21: {}", mid_of_range(1, 21));
}

// this function gets the middle of a given range
fn mid_of_range(low: u32, high: u32) -> u32 {
    let range: f32 = high as f32 - low as f32;

    let half: f32 = range / 2f32;

    // number was whole
    if half % 0.5f32 == 0f32 {
        return half as u32;
    } else {
        return half as u32 - 1;
    }
}
