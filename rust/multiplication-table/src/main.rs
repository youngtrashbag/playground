fn main() {
    println!("Hello, world!");
    let x_len: u8 = 10;
    let y_len: u8 = 10;

    let mut buf_text: String = String::from("");

    buf_text.push_str("\tMULTIPLICATION TABLE\n");

    for _ in 0..x_len {
        buf_text.push_str("\t====");
    }
    buf_text.push_str("\n");
    for tr in 1..x_len + 1 {
        buf_text.push_str(&format!("\t {} ||", tr).to_string());
    }
    buf_text.push_str("\n");
    for _ in 0..x_len {
        buf_text.push_str("\t====");
    }
    buf_text.push_str("\n");

    for yy in 1..y_len + 1 {
        // index line
        buf_text.push_str(&format!("\t {} ||", yy).to_string());

        // actually calculating lines
        for xx in 2..x_len + 1 {
            buf_text.push_str(&format!("\t {} |", yy * xx).to_string());
        }
        buf_text.push_str("\n");

        // printing line with dashes
        for _ in 0..1 {
            buf_text.push_str("\t====");
        }
        for _ in 1..x_len {
            buf_text.push_str("\t----");
        }

        buf_text.push_str("\n");
    }

    print!("{}", buf_text);
}
