#[derive(Copy, Clone)]
pub struct Cashier {
    pub id: u8,
    pub balance: u64
}

impl Cashier {
    pub fn new_cashier(id: u8, balance: u64) -> Self {
        Cashier {
            id,
            balance
        }
    }
}
