import React from 'react';
import { Link } from 'react-router-dom';

export default function Navbar() {
  return (
    <nav>
      <h1 style={{ padding: '0px', margin: 0, textAlign: 'center' }}>
      Everything Store
      </h1>
      <Link to="/" style={{ marginRight: '1rem' }}>Home</Link>
      <Link to="/cart" style={{ marginRight: '1rem' }}>Cart</Link>
      <Link to="/profile">Profile</Link>
    </nav>
  );
}