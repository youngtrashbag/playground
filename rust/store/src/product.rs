#[derive(Copy, Clone)]
pub struct Product {
    pub name: &'static str,
    pub price: u32,
    pub count: u32
}

impl Product {
    pub fn new_product(name: &'static str, price: u32, count: u32) -> Product {
        Product {
            name,
            price,
            count
        }
    }
}
