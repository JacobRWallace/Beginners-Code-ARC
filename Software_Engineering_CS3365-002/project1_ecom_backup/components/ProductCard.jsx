import React from 'react';
import { useCart } from '../context/CartContext';

export default function ProductCard({ product }) {
  const { dispatch } = useCart();

  return (
        <div style={{
        border: '1px solid #aaaaaa',
        padding: '1rem',
        borderRadius: '8px',
        textAlign: 'center',
        width: '200px',
        }}>
        <div style={{
    width: '100%',
    height: '150px',
    overflow: 'hidden',
    borderRadius: '4px',
    backgroundColor: '#f0f0f0'
    }}>
    <img
        src={product.image}
        alt={product.name}
        style={{
        width: '100%',
        height: '100%',
        objectFit: 'cover',
        display: 'block',
        }}
        onError={(e) => {
        e.target.onerror = null;
        e.target.src = 'https://via.placeholder.com/150';
        }}
    />
    </div>
      <h3>{product.name}</h3>
      <p>${product.price.toFixed(2)}</p>
      <button onClick={() => dispatch({ type: 'ADD_TO_CART', payload: product })}>
        Add to Cart
      </button>
    </div>
  );
}