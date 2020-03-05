//hello-world.rs
pub fn hello_world() {
    print!("hello, ");
    print!("world!");
}

//print-test.rs
pub fn print_test() {
    for i in 1..=3 {
        println!("i:{} i:{}", i, i);
    }
    space(0);
    for y in 1..=3 {
        for x in 1..=3 {
            println!("x:{0} y:{1}", x, y);
        }
    }
    
}

pub fn space(newline_count: i32) {
    for _ in 0..newline_count {
        print!("\n");
    }
}

//for-test.rs
pub fn for_test() {
    //iterates from 0 to 9 -> 10 times
    for i in 0..10 {
        println!("\t{}", i);
        continue;
    }
    //only for spacing
    println!("");
    //iterates from 1 to 10 -> 10 times
    for i in 1..=10 {
        println!("\t{}", i);
        continue;
    }
}
