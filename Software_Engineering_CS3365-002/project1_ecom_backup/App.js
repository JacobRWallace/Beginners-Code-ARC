import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Navbar from './components/Navbar';
import Home from './pages/Home';
import Cart from './pages/Cart';
import Profile from './pages/Profile';
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
            <Route path="/profile" element={<Profile />} />
          </Routes>
        </div>
        <footer>
          E-Commerce Project by Jacob Wallace
        </footer>
      </Router>
    </CartProvider>
  );
}

export default App;