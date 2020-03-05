extern crate rand;

mod tests;
mod random;
use random::random_test;
use random::RandomStruct;

fn main() {
    let random_data: Vec<RandomStruct> = random_test(500, 57);
    // tests::hello_world();
    // tests::print_test();
    // tests::for_test();

    tests::space(1);

    let mut i: u16 = 0;
    //iterating through each random_data element in vector
    for rd in random_data.iter() {
        i += 1;

        //println!("Matching Number: {0} on iteration {1}", rd.number, rd.iteration);
        //println!("1 in {0} or a {1} in 1 chance", rd.range, (1.0 / rd.range as f64));
        println!("num:{0}\titer:{1}", rd.number, rd.iteration);
        tests::space(1);
    }

    println!("In total {0} matching Numbers.", i);

    tests::space(1);

}
