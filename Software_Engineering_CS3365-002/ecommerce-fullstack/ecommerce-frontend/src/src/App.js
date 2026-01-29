import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Navbar from './components/Navbar';
import Home from './pages/Home';
import Cart from './pages/Cart';
import Account from './pages/Account';
import { CartProvider } from './context/CartContext';

function App() {
  return (
    <CartProvider>
      <Router>
        <Navbar />
        <div style={{ padding: '1rem' }}>
          <Routes>
            <Route path="/" element={<Home />} />
            <Route path="/cart" element={<Cart />} />
            <Route path="/account" element={<Account />} />
          </Routes>
        </div>
        <footer>
          E-Commerce Project :: Jacob Wallace
        </footer>
      </Router>
    </CartProvider>
  );
}

export default App;